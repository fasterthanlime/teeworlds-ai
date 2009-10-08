import AI, Grid, Vector2

NddAI: class extends AI {
	
	ZOOM := static 10 as Float
	
	JUMP_THRESHOLD := static 4
	MAX_BUMP := static 10
	AIM_THRESHOLD := static 200
	SHOOT_THRESHOLD := static 120
	
	bumpCount := 0
	left := true
	
	nextJump := 0
	printCount := 0
	
	stableCount := 0
	
	grid = null : Grid
	
	lastx := 0.0; lasty := 0.0
	
	stepImpl: func (info: GameInfo@) {
		
		if(!grid) {
			grid = Grid new(220, 150)
			//dbg_msg("ia", "Created a %dx%d grid.", grid width, grid height)
		}
		
		//dbg_msg("ia", "t %.2f pos (%.0f, %.0f) last (%.0f, %.0f), bumpCount %d, nextJump %d, hookCount %d",
			//info time, info pos x, info pos y, lastx, lasty, bumpCount, nextJump, hookCount)
			
		tryJump := rand() % 25 == 0
		//tryJump := false
		//tryJump := true
		
		//if(hookCount > 0) {
			//mouse(-20, -60)
		//}
		
		gridx := (info pos x / ZOOM) as Int
		gridy := (info pos y / ZOOM) as Int
		for(offx: Int in (-2)..3) {
			for(offy: Int in (-2)..3) {
				grid empty(gridx + offx, gridy + offy)
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
		
		if(bestMatch != -1 && bestDist != 0) {

			pos := info chars[bestMatch]
			dist := bestDist
			
			//dbg_msg("ia", "Following bestMatch = %d, dist = %.2f", bestMatch, dist)
			
			left = (pos x < info pos x)
			tryJump = (pos y < info pos y)
			
			if(dist < AIM_THRESHOLD) {
				vec := pos - info pos
				//mouse(vec x, vec y)
				//dbg_msg("ia", "Aiming at (%.0f, %.0f) dist = %.2f!!", vec x, vec y, dist)
			}
			
			if(dist < SHOOT_THRESHOLD) {
				fire()
				//dbg_msg("ia", "Firing!!")
			}
			
		}
		
		if((lastx - info pos x) abs() < 3.0) {
			bumpCount += 1
		} else {
			bumpCount = 0
		}
		
		spanx := 5
		spany := 4
		hasDE := grid search(gridx + (left ? -8 : 8), gridy + 2, spanx, spany, Blocks DEADEND)
		if(hasDE) {
			jump()
		}
		
		hasGround := grid search(gridx, gridy + 4, 2, 2, Blocks WALL)
		if(hasGround) {
			grid ground(gridx + (left ? -3 : 3), gridy + 3)
		}
		
		hasCeil := grid search(gridx, gridy - 4, 2, 2, Blocks WALL)
		if(hasCeil) {
			grid ceil(gridx + (left ? -3 : 3), gridy - 4)
		}
		
		ceilx, ceily : Int
		ceilDist := grid searchNearest(gridx, gridy - 30, 70, 70, Blocks CEIL, ceilx&, ceily&)
		if(ceilDist < 100) {
			difffx := ceilx * ZOOM - info pos x as Int
			difffy := ceily * ZOOM - info pos y as Int
			//printf("difff = (%d, %d)\n", difffx, difffy)
			mouse(difffx, difffy)
			if(ceilDist < 90 && ceilDist > 30 && hookCount < -20) {
				hook(15)
			}
		}

		if(bumpCount == JUMP_THRESHOLD) {
			//jump()
		} else if(tryJump && nextJump <= 0) {
			srand(info time)
			nextJump = rand() % 50 + 20
			jump()
			hook(15)
		}
		if(nextJump >= 0) nextJump -= 1
		
		if(bumpCount >= MAX_BUMP) {
			bumpCount = 0

			//hasWall := grid search(gridx + (left ? -8 : 8), gridy + 2, spanx, spany, Blocks WALL)
			if(/*hasWall && */ hookCount <= 0) {
				off2x := left ? -5 : 5
				for(offx: Int in (-1)..1) {
					for(offy: Int in (2)..(5)) {
						grid deadend(gridx + offx + off2x, gridy + offy)
					}
				}
			}
			
			left = !left
		}
		
		if (left) left(); else right()
		
		printCount -= 1
		if(printCount <= 0) {
			printCount = 40
			grid print()
		}
	
		//answer action print(); println()
		
		lastx = info pos x
		lasty = info pos y
		
	}
	
}
