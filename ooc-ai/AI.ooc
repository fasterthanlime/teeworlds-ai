include stdint
use math

Action: cover from UInt32 {

	print: func {
		printf("[ ")
		if(this & Actions JUMP)  printf("jump ")
		if(this & Actions LEFT)  printf("left ")
		if(this & Actions RIGHT) printf("right ")
		if(this & Actions FIRE)  printf("fire ")
		printf("]")
	}
	
}

Actions: class {
	
	NONE  = 0,
	JUMP  = 0b00000001,
	LEFT  = 0b00000010,
	RIGHT = 0b00000100,
	FIRE  = 0b00001000 : static const Action
	
}

AI: abstract class {

	step: abstract func (localTime: Float, posx, posy: Float) -> Action

}

getAI: func -> AI { DummyAI new() }

dbg_msg: extern proto func (module, fmt: String, ...)

DummyAI: class extends AI {
	
	MAX_BUMP := static 20
	bumpCount := 0
	left := true
	
	lastx := 0.0; lasty := 0.0
	
	step: func (localTime: Float, posx, posy: Float) -> Action {
		
		dbg_msg("ia", "t = %.2f\t pos = (%.0f, %.0f) last = (%.0f, %.0f), bumpCount = %d", localTime, posx, posy, lastx, lasty, bumpCount)
		
		action = 0 : Action
		
		if((lastx - posx) abs() < 3.0) {
			bumpCount += 1
		} else {
			bumpCount = 0
		}
		
		if(bumpCount >= MAX_BUMP) {
			bumpCount = 0
			left = !left
			action |= Actions JUMP
		}
		action |= (left ? Actions LEFT : Actions RIGHT)
	
		action print()
		println()
		
		lastx = posx
		lasty = posy
	
		return action
		
	}
	
}

BlobbyAI: class extends AI {
	
	step: func (localTime: Float, posx, posy: Float) -> Action {
		
		action = 0 : Action
		
		if(rand() % 50 == 10){
			mouse_pos.x = cos(rand() % 100) * 100 + 50;
			mouse_pos.y = sin(rand() % 100) * 100 + 50;
		}
		
		if(rand() % 30 == 10){
			action |= JUMP
		}
		
		if(rand() % 40 == 10){
			action |= FIRE
		}
		
		//dbg_msg("ai","diff: %f",target_pos.x - char_posx);
		if(target_pos.x - posx > 0){
			input_data.direction = 1;
		}
		else if(abs(target_pos.x - posx) < 15){
			input_data.direction = 0;
		}
		else{
			input_data.direction = -1;
		}
	
		return action
		
	}
}
