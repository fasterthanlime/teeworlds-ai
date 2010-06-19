import Vector2, Action
include stdint
use math

dbg_msg: extern proto func (module, fmt: String, ...)

Answer: cover {
	action: Action
	target, mouse: Vector2*
    prevWeapon: UInt32
    nextWeapon: UInt32
    wantedWeapon: UInt32
}

GameInfo: cover {
	time: Float
	localCid: Int
	pos, target, mouse: Vector2
	
	numChars: Int
	chars: Vector2*
}

/**
 * 
 */
AI: abstract class {

	answer : Answer
	
	hookCount := 0
	
	mouseWish := Vector2 new(0, 0)
	mouseReal := Vector2 new(0, 0)
	mouseSpeed := 0.3

	stepImpl: abstract func (info: GameInfo@)

	step: func (info: GameInfo) -> Answer {
		answer action = 0
		answer target = null
		answer mouse = null

		stepImpl(info&)
		
		hookCount -= 1
		if(hookCount > 0) {
			hook()
		}
		
		diff := mouseWish - mouseReal
		//printf("mouseReal = (%.0f, %.0f), mouseWish = (%.0f, %.0f), diff = (%.0f, %.0f)\n",
			//mouseReal x, mouseReal y, mouseWish x, mouseWish y, diff x, diff y)
		diff = diff * mouseSpeed
		mouseReal = mouseReal + diff
		
		answer mouse = mouseReal&
		
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
		mouseWish x = x
		mouseWish y = y
	}
	
	mouseNow: func (x, y: Float) {
		mouseReal x = x
		mouseReal y = y
		mouseWish x = x
		mouseWish y = y
	}
	
}
