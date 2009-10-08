import AI, Vector2

EagleAI: class extends AI {
	
	dist: func (info: GameInfo@, a,b: Int) -> Double{
		if(true){
			return (info chars[a] - info chars[b]) length()
		}
	}
	
	checkID: func {
	}
	
	
	stepImpl: func (info: GameInfo@) {
		if(info numChars == 1 && rand() % 40 == 10){
			x := rand() % 100
			mouse( cos(x)*100 , sin(x)*100)
		}
		
		else if(info numChars != 1){
			target := info chars[0] - info chars[1]
			dst := dist(info&,0,1)
			dbg_msg("EagleAI","target_dist: %f",dst)
			mouse(target x, target y)
			if(dst < 600) {
				fire()
				if(dst < 300){
					hook(15)
				}
			}
		}
		else{
			dbg_msg("EagleAI","!no target!")
		}
		
	}
	
}
