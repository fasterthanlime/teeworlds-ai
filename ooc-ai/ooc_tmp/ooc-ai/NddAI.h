/* NddAI header file, generated with ooc */
#ifndef ___NddAI__
#define ___NddAI__


struct _NddAI;
typedef struct _NddAI NddAI;
struct _NddAIClass;
typedef struct _NddAIClass NddAIClass;

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
#include <ooc-ai/AI.h>

struct _NddAI
{
	struct _AI __super__;
	lang__Int bumpCount;
	lang__Bool left;
	lang__Int nextJump;
	lang__Float lastx;
	lang__Float lasty;
};


struct _NddAIClass
{
	struct _AIClass __super__;
	NddAI * (*new)();
	lang__Void (*init)(NddAI *);
	lang__Int JUMP_THRESHOLD;
	lang__Int MAX_BUMP;
};


lang__Class *NddAI_class();

lang__Void NddAI___load__();
lang__Void NddAI___defaults__(NddAI *this);
lang__Void NddAI___defaults___impl(NddAI *this);
lang__Void NddAI___destroy__(NddAI *this);
lang__Void NddAI___destroy___impl(NddAI *this);
NddAI *NddAI_new();
lang__Void NddAI_init(NddAI *this);
lang__Void NddAI_init_impl(NddAI *this);
lang__Void NddAI_stepImpl(NddAI *this, GameInfo *info);
lang__Void NddAI_stepImpl_impl(NddAI *this, GameInfo *info);

lang__Void _NddAI_load();

#endif // ___NddAI__

