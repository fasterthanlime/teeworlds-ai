/* AI header file, generated with ooc */
#ifndef ___AI__
#define ___AI__


#include <stdint.h>
typedef struct _Answer Answer;
struct _Actions;
typedef struct _Actions Actions;
struct _ActionsClass;
typedef struct _ActionsClass ActionsClass;
typedef struct _Vector2 Vector2;
typedef struct _GameInfo GameInfo;
typedef uint32_t Action;
struct _AI;
typedef struct _AI AI;
struct _AIClass;
typedef struct _AIClass AIClass;

#include <sdk/lang/Iterator.h>
#include <sdk/lang/String.h>
#include <sdk/lang/Float.h>
#include <sdk/lang/Interface.h>
#include <sdk/lang/Range.h>
#include <sdk/lang/Object.h>
#include <sdk/lang/TypeInfo.h>
#include <sdk/lang/Double.h>
#include <sdk/lang/Exception.h>
#include <sdk/lang/Char.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/Bool.h>
#include <sdk/lang/stdio.h>
#include <sdk/lang/Iterable.h>
#include <sdk/lang/Int.h>
#include <sdk/lang/LLong.h>
struct _Answer 
{
	Action action;
	Vector2 *target, *mouse;
};

lang__Class *Answer_class();
struct _Actions
{
	struct _lang__Object __super__;
};


struct _ActionsClass
{
	struct _lang__ObjectClass __super__;
	Actions * (*new)();
	lang__Void (*init)(Actions *);
	Action NONE, JUMP, LEFT, RIGHT, FIRE, HOOK;
};


lang__Class *Actions_class();

lang__Void Actions___load__();
lang__Void Actions___defaults__(Actions *this);
lang__Void Actions___defaults___impl(Actions *this);
lang__Void Actions___destroy__(Actions *this);
lang__Void Actions___destroy___impl(Actions *this);
Actions *Actions_new();
lang__Void Actions_init(Actions *this);
lang__Void Actions_init_impl(Actions *this);
struct _Vector2 
{
	lang__Float x, y;
};

lang__Class *Vector2_class();
lang__Double Vector2_length(Vector2 this);struct _GameInfo 
{
	lang__Float time;
	Vector2 pos, target, mouse;
	lang__Int numChars;
	Vector2 *chars;
};

lang__Class *GameInfo_class();
lang__Class *Action_class();
lang__Void Action_print(Action this);
struct _AI
{
	struct _lang__Object __super__;
	Answer answer;
	lang__Int hookCount;
};


struct _AIClass
{
	struct _lang__ObjectClass __super__;
	lang__Void (*stepImpl)(AI *, GameInfo *);
	Answer (*step)(AI *, GameInfo);
	lang__Void (*jump)(AI *);
	lang__Void (*left)(AI *);
	lang__Void (*right)(AI *);
	lang__Void (*fire)(AI *);
	lang__Void (*hook)(AI *);
	lang__Void (*hook_count)(AI *, lang__Int);
	lang__Void (*target)(AI *, lang__Float, lang__Float);
	lang__Void (*mouse)(AI *, lang__Float, lang__Float);
};


lang__Class *AI_class();

lang__Void AI___load__();
lang__Void AI___defaults__(AI *this);
lang__Void AI___defaults___impl(AI *this);
lang__Void AI___destroy__(AI *this);
lang__Void AI___destroy___impl(AI *this);
lang__Void AI_stepImpl(AI *this, GameInfo *info);
Answer AI_step(AI *this, GameInfo info);
Answer AI_step_impl(AI *this, GameInfo info);
lang__Void AI_jump(AI *this);
lang__Void AI_jump_impl(AI *this);
lang__Void AI_left(AI *this);
lang__Void AI_left_impl(AI *this);
lang__Void AI_right(AI *this);
lang__Void AI_right_impl(AI *this);
lang__Void AI_fire(AI *this);
lang__Void AI_fire_impl(AI *this);
lang__Void AI_hook(AI *this);
lang__Void AI_hook_impl(AI *this);
lang__Void AI_hook_count(AI *this, lang__Int time);
lang__Void AI_hook_count_impl(AI *this, lang__Int time);
lang__Void AI_target(AI *this, lang__Float x, lang__Float y);
lang__Void AI_target_impl(AI *this, lang__Float x, lang__Float y);
lang__Void AI_mouse(AI *this, lang__Float x, lang__Float y);
lang__Void AI_mouse_impl(AI *this, lang__Float x, lang__Float y);

extern lang__Void dbg_msg(lang__String module, lang__String fmt, ...);
Vector2 __OP_SUB_Vector2_Vector2__Vector2(Vector2 v1, Vector2 v2);
Vector2 __OP_MUL_Vector2_Float__Vector2(Vector2 v, lang__Float f);
lang__Void _AI_load();

#endif // ___AI__

