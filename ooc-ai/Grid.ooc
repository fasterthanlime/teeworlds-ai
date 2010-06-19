import Vector2, structs/ArrayList, math

Block: cover from Int

Blocks: class {
	
	WALL 	= 0,
	EMPTY 	= 1,
	DEADEND = 2,
	GROUND 	= 3,
	CEIL 	= 4,
	FALL 	= 5 : static const Block
	
}

Grid: class {
	
	width, height: Int
	data: ArrayList<Block>
	
	init: func(=width, =height) {
		printf("Creating a %dx%d grid.\n", width, height)
		data = ArrayList<Block> new(width * height)
        
        for(i in 0..(width * height)) {
            data add(Blocks WALL)
        }
	}
	
	print: func {
		
		for(x in 0..(width / 2 + 2)) {
			printf("=")
		}
		println()
		
		for(y in 0..height) {
			if(y % 4 < 3) continue
			printf("|")
			for(x in 0..width) {
				if(x % 2 == 0) continue
				val := get(x, y)
				printf("%s", match val {
					case Blocks EMPTY   => " "
					case Blocks WALL    => "."
					case Blocks DEADEND => "X"
					case Blocks GROUND  => "_"
					case Blocks CEIL	=> "~"
					case Blocks FALL 	=> "v"
					case => " "
				})
			}
			printf("|")
			println()
		}
		
		for(x in 0..(width / 2 + 2)) {
			printf("=")
		}
		println()
		
	}
	
	get: func (x, y: Int) -> Block {
		if(x < 0 || x >= width || y < 0 || y >= height) {
			return Blocks WALL
		}
		return data get(y * width + x)
	}
	
	set: func (x, y: Int, value: Block) {
		if(x < 0 || x >= width || y < 0 || y >= height) {
			return
		}
		data set(y * width + x, value)
	}
	
	empty: func (x, y: Int) {
		val := get(x, y)
		if(val != Blocks DEADEND) {
			set(x, y, Blocks EMPTY)
		}
	}
	
	wall: func (x, y: Int) {
		set(x, y, Blocks WALL)
	}
	
	ground: func (x, y: Int) {
		set(x, y, Blocks GROUND)
	}
	
	ceil: func (x, y: Int) {
		set(x, y, Blocks CEIL)
	}
	
	deadend: func (x, y: Int) {
		val := get(x, y)
		if(val != Blocks FALL) {
			set(x, y, Blocks DEADEND)
		}
	}
	
	fall: func (x, y: Int) {
		set(x, y, Blocks FALL)
	}
	
	search: func (gridx, gridy, spanx, spany: Int, type: Block) -> Bool {
		for(y in (gridy - spany)..(gridy + spany)) {
			for(x in (gridx - spanx)..(gridx + spanx)) {
				val := get(x, y)
				if(val == type) return true
			}
		}
		return false
	}
	
	searchNearest: func (gridx, gridy, nearestx, nearesty, spanx, spany: Int, type: Block, ceilx, ceily: Int@) -> Bool {
		MAX := 99999999
		bestDist := MAX
		
		for(y in (gridy - spany)..(gridy + spany)) {
			for(x in (gridx - spanx)..(gridx + spanx)) {
				val := get(x, y)
				if(val == type) {
					diffx := x - nearestx
					diffy := y - nearesty
					dist := sqrt(diffx*diffx + diffy*diffy)
					if(dist < bestDist) {
						bestDist = dist
						ceilx = x
						ceily = y
					}
				}
			}
		}
		
		return bestDist != MAX
	}
	
}












