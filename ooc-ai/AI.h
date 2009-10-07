#ifndef ___AI__
#define ___AI__

#include <stdint.h>

#define Actions_JUMP   0x01
#define Actions_LEFT   0x02
#define Actions_RIGHT  0x04
#define Actions_FIRE   0x08

typedef uint32_t Action;
typedef struct _AI AI;

Action AI_step(AI *_this, float localTime, float posx, float posy);
void _AI_load();
AI *getAI();

#endif // ___AI__

