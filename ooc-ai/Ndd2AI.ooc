import AI, Grid, Vector2, Canvas, math, math/Random

Ndd2AI: class extends AI {
	
	// constants
	ZOOM := static 11.0
	BUMP_THRESHOLD := static 5
    
    left := true
    bumpCount := 0
	
    printCount := 0
    
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
		if((lastPos x - info pos x) abs() < 4.0) {
			bumpCount += 1
		} else {
			bumpCount = 0
		}
		
		// jump if there's a deadend in front of us
		if(grid search(gridx + (left ? -8 : 8), gridy + 2, 5, 4, Blocks DEADEND)) {
			jump()
		}
        
        if(bumpCount > BUMP_THRESHOLD) {
            bumpCount = 0
            grid deadend(gridx + (left ? -6 : 6), gridy + 4)
            left = !left
        }
		
		// detect ground
		hasGround := grid search(gridx, gridy + 4, 2, 2, Blocks WALL)
		if(hasGround) {
			grid ground(gridx + (left ? -3 : 3), gridy + 5)
		}
		
		// detect ceilings
		hasCeil := grid search(gridx, gridy - 4, 2, 2, Blocks WALL)
		if(hasCeil) {
			grid ceil(gridx + (left ? -3 : 3), gridy - 6)
		}
		
		printCount -= 1
		if(printCount <= 0) {
			printCount = 3
			grid print(gridx, gridy)
		}
		
		lastPos x = info pos x
		lastPos y = info pos y
		
	}
	
}
