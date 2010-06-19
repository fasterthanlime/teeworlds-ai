import AI, Grid, Vector2, Canvas, math, math/Random

NddAI: class extends AI {
	
	// constants
	ZOOM := static 11.0
	JUMP_THRESHOLD := static 4
	BUMP_THRESHOLD := static 5
    
    FOLLOW_THRESHOLD := static 420
	AIM_THRESHOLD := static 320
	SHOOT_THRESHOLD := static 200
    HAMMER_THRESHOLD := static 80

	followCount := 0
	follow := false
	
    hookIn := -1
    
	left := true
    leftCount := 0
	
	nextJump := 0
	bumpCount := 0
	printCount := 0
    
    nextPrev := false
	
	lastPos : Vector2
	
	grid := Grid new(300, 200)
	
	stepImpl: func (info: GameInfo@) {
        
        answer prevWeapon = false
        answer nextWeapon = false
        answer wantedWeapon = 0
		
		// get our grid coordinates
		gridx := (info pos x / ZOOM) as Int
		gridy := (info pos y / ZOOM) as Int
        
        if (left) {
            left()
            mouse(-50, 0)
        } else {
            right()
            mouse(50, 0)
        }
		
		// if we reached this position, it means it's empty, right?
		for(offx: Int in (-2)..3) {
			for(offy: Int in (-2)..3) {
				grid empty(gridx + offx, gridy + offy)
			}
		}
		
		// 
		//if((lastPos x - info pos x) abs() < 4.0) {
        if((lastPos x - info pos x) abs() < 5.0) {
			bumpCount += 1
		} else {
			bumpCount = 0
		}
		
		// jump if there's a deadend in front of us
		if(grid search(gridx + (left ? -8 : 8), gridy + 2, 5, 4, Blocks DEADEND)) {
			jump()
		}
		
		// detect ground
		hasGround := grid search(gridx, gridy + 4, 2, 2, Blocks WALL)
		if(hasGround) {
			grid ground(gridx + (left ? -3 : 3), gridy + 3)
		}
		
		// detect ceilings
		hasCeil := grid search(gridx, gridy - 4, 2, 2, Blocks WALL)
		if(hasCeil) {
			grid ceil(gridx + (left ? -3 : 3), gridy - 4)
		}

        /*
		// from time to time, try to hook 
		ceilx, ceily : Int
		ceilDist := grid searchNearest(gridx, gridy - 40, gridx, gridy, 40, 40, Blocks CEIL, ceilx&, ceily&)
		if(ceilDist < 100) {
            // convert grid coords to world coords
			diffx := ceilx * ZOOM - info pos x as Int
			diffy := ceily * ZOOM - info pos y as Int
			mouse(diffx, diffy)
			// if not too far, not too close, and some time since last hook
			if(ceilDist < 90 && ceilDist > 30 && hookCount < -20) {
				hook(15)
			}
		}
        */

		// from time to time, try to jump to explore the upper part of the map
		// except if we're trying to determine if there's a deadend there.
		tryJump := (bumpCount == 0 && Random randInt(0, 25) == 0)
		
        if(Random randInt(1, 50) == 30) {
            if(nextPrev) {
                answer nextWeapon = true
                nextPrev = false
            } else {
                answer prevWeapon = true
                nextPrev = true
            }
        }
		
		// if we've reached a deadend (e.g. we've bumped for some time), mark it
		if(bumpCount >= BUMP_THRESHOLD) {
			bumpCount = 0
			hasWall := grid search(gridx + (left ? -8 : 8), gridy + 2, 5, 4, Blocks WALL)
			if(hasWall && hookCount <= 0) {
				for(offy: Int in (2)..(5)) {
					grid deadend(gridx + (left ? -5 : 5), gridy + offy)
				}
			}
			// oh, and turn back. there's no use to keep trying.
            if(leftCount == 0) {
                left = !left
                leftCount = 20
            }
		}
		
        bestDist := 99999.0
		bestMatch := -1	
		for(i in 0..info numChars) {
			
			if(i == info localCid) continue // that's us
			
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

			pos := info chars[bestMatch]
			dist := bestDist
			
			//dbg_msg("ia", "Following bestMatch = %d, dist = %.2f", bestMatch, dist)
			
			diff := info pos - pos
			halfDiff := diff * 0.5
			
            tryJump = (pos y < info pos y)
            
            if(leftCount == 0) {
                left = (pos x < info pos x)
                leftCount = 20
            } else {
                leftCount -= 4
                if(leftCount < 0) leftCount = 0
            }
            
			if(dist < AIM_THRESHOLD) {
				vec := pos - info pos
				mouseNow(vec x, vec y)
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
        
        if(leftCount > 0) leftCount -= 1
        
        // if it's supposed to jump, then jump and hook!
		if(tryJump && nextJump <= 0) {
			srand(info time)
			nextJump = Random randInt(0, 50) + 20
			jump()
            
            mouseNow(left ? 5 : -5, -100)
            hookIn = 5
		}
        if(hookIn >= 0) {
            hookIn -= 1
            if(hookIn == 0) {
                hook(15)
            }
        }
        
		if(nextJump >= 0) nextJump -= 1
		
		printCount -= 1
		if(printCount <= 0) {
			printCount = 5
			grid print(gridx, gridy)
		}
		
		lastPos x = info pos x
		lastPos y = info pos y
		
	}
	
}
