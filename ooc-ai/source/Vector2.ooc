use math
import math

Vector2: cover {
	x, y: Float

	new: static func (.x, .y) -> Vector2 {
		this : This
		this x = x
		this y = y
		return this
	}

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

operator + (v1, v2: Vector2) -> Vector2 {
	v : Vector2
	v x = v1 x + v2 x
	v y = v1 y + v2 y
	return v
}

operator * (v: Vector2, f: Float) -> Vector2 {
	vout : Vector2
	vout x = v x * f
	vout y = v y * f
	return vout
}
