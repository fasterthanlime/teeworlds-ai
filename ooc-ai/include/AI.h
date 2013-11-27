#ifndef ___AI__
#define ___AI__

#include <stdint.h>

#define Actions_JUMP   0x01
#define Actions_LEFT   0x02
#define Actions_RIGHT  0x04
#define Actions_FIRE   0x08
#define Actions_HOOK   0x10

typedef struct _AI AI;

struct Vector2 {
	float x, y;
};

struct Answer {
	uint32_t action;
	Vector2 *target, *mouse;
};

struct GameInfo {
	float time;
	int localCid;
	struct Vector2 pos, target, mouse;
	
	int numChars;
	struct Vector2 *chars;
};

void _ooc_ai_load();

AI *getAI();
struct Answer AI_step(AI *_this, struct GameInfo info);

#endif // ___AI__

