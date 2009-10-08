import AI

NddAI: class extends AI {
	
	JUMP_THRESHOLD := static 3
	MAX_BUMP := static 20
	AIM_THRESHOLD := static 200
	SHOOT_THRESHOLD := static 50
	
	bumpCount := 0
	left := true
	
	nextJump := 0
	
	lastx := 0.0; lasty := 0.0
	
	stepImpl: func (info: GameInfo@) {
		
		//dbg_msg("ia", "t %.2f pos (%.0f, %.0f) last (%.0f, %.0f), bumpCount %d, nextJump %d, hookCount %d",
			//info time, info pos x, info pos y, lastx, lasty, bumpCount, nextJump, hookCount)
			
		tryJump := false
		
		if(hookCount > 0) {
			mouse(-20, -60)
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
				dbg_msg("ia", "Found better match = %d, diffx = %.2f, diffy = %.2f, dist = %.2f", i, diffx, diffy, dist)
				bestDist = dist
				bestMatch = i
			}
		}
		
		if(bestMatch != -1 && bestDist != 0) {

			pos := info chars[bestMatch]
			dist := bestDist
			
			dbg_msg("ia", "Following bestMatch = %d, dist = %.2f", bestMatch, dist)
			
			left = (pos x < info pos x)
			tryJump = (pos y < info pos y)
			
			if(dist < AIM_THRESHOLD) {
				vec := pos - info pos
				mouse(vec x, vec y)
				dbg_msg("ia", "Aiming at (%.0f, %.0f) dist = %.2f!!", vec x, vec y, dist)
			}
			
			if(dist < SHOOT_THRESHOLD) {
				fire()
				dbg_msg("ia", "Firing!!")
			}
			
		}
		
		if((lastx - info pos x) abs() < 3.0) {
			bumpCount += 1
		} else {
			bumpCount = 0
		}
		
		if(bumpCount == JUMP_THRESHOLD) {
			jump()
		} else if(tryJump && nextJump <= 0) {
			srand(info time)
			nextJump = rand() % 50 + 20
			jump()
			hook(15)
		}
		if(nextJump >= 0) nextJump -= 1
		
		if(bumpCount >= MAX_BUMP) {
			bumpCount = 0
			left = !left
		}
		if (left) left(); else right()
	
		//answer action print(); println()
		
		lastx = info pos x
		lasty = info pos y
		
	}
	
}
