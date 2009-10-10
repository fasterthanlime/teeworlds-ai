import AI, Grid, Vector2

NddAI: class extends AI {
	
	// constants
	ZOOM := static 11.0
	JUMP_THRESHOLD := static 4
	BUMP_THRESHOLD := static 5
	AIM_THRESHOLD := static 280
	SHOOT_THRESHOLD := static 180

	followCount := 0
	follow := false
	
	left := true
	
	nextJump := 0
	bumpCount := 0
	printCount := 0
	
	lastPos : Vector2
	
	grid := Grid new(300, 200)
	
	stepImpl: func (info: GameInfo@) {
		
		// get our grid coordinates
		gridx := (info pos x / ZOOM) as Int
		gridy := (info pos y / ZOOM) as Int
		
		// if we reached this position, it means it's empty, right?
		for(offx: Int in (-2)..3) {
			for(offy: Int in (-2)..3) {
				grid empty(gridx + offx, gridy + offy)
			}
		}
		
		// 
		if((lastPos x - info pos x) abs() < 3.0) {
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

		// from time to time, try to jump to explore the upper part of the map
		// except if we're trying to determine if there's a deadend there.
		tryJump := (bumpCount == 0 && rand() % 25 == 0)
		
		// if it's supposed to jump, then jump and hook!
		if(tryJump && nextJump <= 0) {
			srand(info time)
			nextJump = rand() % 50 + 20
			jump()
			hook(15)
		}
		if(nextJump >= 0) nextJump -= 1
		
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
			left = !left
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
		
		if(bestMatch != -1 && bestDist != 0) {

			pos := info chars[bestMatch]
			dist := bestDist
			
			//dbg_msg("ia", "Following bestMatch = %d, dist = %.2f", bestMatch, dist)
			
			diff := info pos - pos
			halfDiff := diff * 0.5
			
			if(followCount <= 0) {
				followCount = rand() % 60
				follow := !follow
			}
			
			if(follow) {
				tryJump = (pos y < info pos y)
				left = (pos x < info pos x)
			}
			
			if(dist < AIM_THRESHOLD) {
				vec := pos - info pos
				mouseNow(vec x, vec y)
			}
			
			if(dist < SHOOT_THRESHOLD) {
				fire()
			}
			
		}
		
		if (left) left(); else right()
		
		printCount -= 1
		if(printCount <= 0) {
			printCount = 5
			grid print()
		}
		
		lastPos x = info pos x
		lastPos y = info pos y
		
	}
	
}
