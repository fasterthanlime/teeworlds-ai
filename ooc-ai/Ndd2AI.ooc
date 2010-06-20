import AI, Grid, Vector2, Canvas, math, math/Random

Ndd2AI: class extends AI {
	
	// constants
	ZOOM := static 11.0
	BUMP_THRESHOLD := static 5
    
    FOLLOW_THRESHOLD := static 300
    AIM_THRESHOLD := static 320
    SHOOT_THRESHOLD := static 200
    HAMMER_THRESHOLD := static 80
    
    left := true
    up := false
    bumpCount := 0
    
    hookCount := -1
    
    holeCounter := 0
    deadEndCounter := 0
    
    upCounter := 0
    
    follow := true
    
    printCount := 0
    
    lastPos : Vector2
    targetPos : Vector2
    
    gridx, gridy: Int
	
	grid := Grid new(300, 200)
    canvas := Canvas new(1024, 768)
    
    init: func {
        canvas addPaint(|cr| this grid paint(cr))
        canvas addPaint(|cr|
            cr setSourceRGB(0.5, 0.0, 0.5)
            cr rectangle(this targetPos x / ZOOM - 3, this targetPos y / ZOOM - 3, 6, 6)
            cr fill()
            
            cr setSourceRGB(0.0, 0.5, 0.5)
            cr rectangle(this lastPos x / ZOOM - 3, this lastPos y / ZOOM - 3, 6, 6)
            cr fill()
            
            cr setSourceRGB(0.0, 1.0, 0.5)
            cr rectangle(this lastPos x / ZOOM + (left ? -4 : 4) - 1, this lastPos y / ZOOM + 4 - 1, 2, 2)
            cr fill()
            
            cr setSourceRGB(0.0, 0.3, 0.5)
            cr rectangle(this lastPos x / ZOOM + (left ? -8 : 8) - 3, this lastPos y / ZOOM + 2 - 2, 7, 4)
            cr fill()
        )
    }
    	
	stepImpl: func (info: GameInfo@) {
        
        canvas update()
        
        answer prevWeapon = false
        answer nextWeapon = false
        answer wantedWeapon = 0
        
        dbg_msg("ia", "Got %d players!\n", info numPlayers)
		
		// get our grid coordinates
		gridx = (info pos x / ZOOM) as Int
		gridy = (info pos y / ZOOM) as Int
        
        if (left) {
            left()
            if(hookCount == -1) mouse(-100, 0)
        } else {
            right()
            if(hookCount == -1) mouse(100, 0)
        }
		
		// if we reached this position, it means it's empty, right?
		for(offx: Int in (-1)..2) {
			for(offy: Int in (-3)..4) {
				grid empty(gridx + offx, gridy + offy)
			}
		}
		
		// 
		if((lastPos x - info pos x) abs() < 4.0) {
			bumpCount += 1
		} else {
			bumpCount = 0
		}
        
        if(bumpCount > BUMP_THRESHOLD) {
            bumpCount = 0
            grid deadend(gridx + (left ? -1 : 1), gridy + 4)
            // and don't keep trying
            left = !left
        }
		
		// detect ground
		hasGround := grid search(gridx, gridy + 4, 1, 1, Blocks WALL)
		if(hasGround) {
			grid ground(gridx + (left ? -3 : 3), gridy + 5)
		}
        
        dbg_msg("ia", "Local cid is %d", info localCid)
        ourTeam := -1
        for(j in 0..info numPlayers) {
            playerInfo := info playerInfos[j]
            if(playerInfo != null && playerInfo@ cid == info localCid) {
                ourTeam = playerInfo@ team
            }
        }
        dbg_msg("ia", "Our team is %d!", ourTeam)
        
        // detect enemies
        bestDist := 99999.0
		bestMatch := -1	
		for(i in 0..info numChars) {
			
            friendly := false
            
			if(i == info localCid) continue // that's us
            for(j in 0..info numPlayers) {
                playerInfo := info playerInfos[j]
                if(playerInfo) {
                    if(playerInfo@ cid == i && playerInfo@ team == ourTeam) {
                        dbg_msg("ia", "Player %d is our team (%d), shooting!", i, playerInfo@ team)
                        friendly = true
                        break
                    }
                }
            }
            if(friendly) {
                break
            } else {
                dbg_msg("ia", "Not our team, shooting!")
            }
			
			pos := info chars[i]
			if(pos isZero()) continue // non-existent player!
			//dbg_msg("ai", "[ooc] client %d: %f,%f", i, pos x, pos y);
			
			diffx := (pos x - info pos x) abs()
			diffy := (pos y - info pos y) abs()
			
			dist := sqrt(diffx * diffx + diffy * diffy)
			if(dist < bestDist) {
				//dbg_msg("ia", "Found better match = %d, diffx = %.2f, diffy = %.2f, dist = %.2f", i, diffx, diffy, dist)
				bestDist = dist
				bestMatch = i
			}
		}
		
		if(bestMatch != -1 && bestDist < FOLLOW_THRESHOLD) {

			targetPos = info chars[bestMatch]
			dist := bestDist
			
			//dbg_msg("ia", "Following bestMatch = %d, dist = %.2f", bestMatch, dist)
			diff := info pos - targetPos
			halfDiff := diff * 0.5
			
            left = (targetPos x < info pos x)
            up   = (targetPos y > info pos y)
            
            if(!follow) {
                left = !left
                up = !up
            }
            
			if(dist < AIM_THRESHOLD) {
				vec := targetPos - info pos
				mouse(vec x, vec y)
			}
			
            if(dist < SHOOT_THRESHOLD) {
				fire()
			}
            
            if(dist < HAMMER_THRESHOLD) {
                answer wantedWeapon = 1
                hook(15)
            } else {
                answer wantedWeapon = 2
            }
			
		}
        
        upCounter += 1 
        if(upCounter > 200) {
            up = !up
            dbg_msg("ia", "now going %s!", up ? "up" : "down")
            upCounter = 0
        }
        
        // jump if there's a deadend in front of us
		if(grid search(gridx + (left ? -8 : 8), gridy + 2, 7, 4, Blocks DEADEND)) {
            deadEndCounter += 1
            if(deadEndCounter >= 2) {
                deadEndCounter = 0
                dbg_msg("ia", "jump because of deadend!")
                jump()
            }
		} else if(up && !grid search(gridx + (left ? -4 : 4), gridy + 4, 2, 2, Blocks GROUND)) {
            holeCounter += 1
            if(holeCounter >= 3) {
                holeCounter = 0
                dbg_msg("ia", "jump because of hole :x!")
                jump()
                mouse(left ? 50 : -50, -100)
                hookCount = 5
            }
		} else {
            holeCounter = 0
            deadEndCounter = 0
        }
        
        if(hookCount > -1) {
            hookCount -= 1
            if(hookCount == 0) {
                hook(Random randInt(5, 15))
            }
        }
		
		lastPos x = info pos x
		lastPos y = info pos y
		
	}
	
}
