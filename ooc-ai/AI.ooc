include stdint
use math

dbg_msg: extern proto func (module, fmt: String, ...)
srand: extern func(Int)
rand: extern func -> Int

Answer: cover {
	action: Action
	target, mouse: Vector2*
}

Actions: class {
	
	NONE  = 0,
	JUMP  = 0b00000001,
	LEFT  = 0b00000010,
	RIGHT = 0b00000100,
	FIRE  = 0b00001000,
	HOOK  = 0b00010000 : static const Action
	
}

Vector2: cover {
	x, y: Float
}

GameInfo: cover {
	time: Float
	pos, target, mouse: Vector2
	
	numChars: Int
	chars: Vector2*
}

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

/**
 * 
 */
AI: abstract class {

	answer : Answer
	
	hookCount := 0

	stepImpl: abstract func (info: GameInfo@)

	step: func (info: GameInfo) -> Answer {
		answer action = 0
		answer target = null
		answer mouse = null

		stepImpl(info&)
		
		if(hookCount > 0) {
			hookCount -= 1
			hook()
		}
		
		return answer
	}
	
	jump:  func { answer action |= Actions JUMP  }
	left:  func { answer action |= Actions LEFT  }
	right: func { answer action |= Actions RIGHT }
	fire:  func { answer action |= Actions FIRE  }
	hook:  func { answer action |= Actions HOOK  }
	hook:  func ~count (time: Int) { hookCount = time }
	
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