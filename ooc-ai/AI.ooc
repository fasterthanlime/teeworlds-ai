include stdint
use math

dbg_msg: extern proto func (module, fmt: String, ...)

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

	length: func -> Double {
		return sqrt(x*x + y*y)
	}
	
	isZero: func -> Bool { x == 0.0 && y == 0.0 }
}

operator - (v1, v2: Vector2) -> Vector2 {
	v : Vector2
	v x = v1 x - v2 x
	v y = v1 y - v2 y
	return v
}

operator * (v: Vector2, f: Float) -> Vector2 {
	vout : Vector2
	vout x = v x * f
	vout y = v y * f
	return vout
}

GameInfo: cover {
	time: Float
	localCid: Int
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
	
	target: func (x, y: Float) {
		answer target = gc_malloc(Vector2 size)
		answer target@ x = x
		answer target@ y = y
	}
	
	mouse: func (x, y: Float) {
		answer mouse = gc_malloc(Vector2 size)
		answer mouse@ x = x
		answer mouse@ y = y
	}
	
}
