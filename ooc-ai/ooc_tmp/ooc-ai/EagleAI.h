/* EagleAI header file, generated with ooc */
#ifndef ___EagleAI__
#define ___EagleAI__


struct _EagleAI;
typedef struct _EagleAI EagleAI;
struct _EagleAIClass;
typedef struct _EagleAIClass EagleAIClass;

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

struct _EagleAI
{
	struct _AI __super__;
};


struct _EagleAIClass
{
	struct _AIClass __super__;
	EagleAI * (*new)();
	lang__Void (*init)(EagleAI *);
	lang__Double (*dist)(EagleAI *, GameInfo *, lang__Int, lang__Int);
	lang__Void (*checkID)(EagleAI *);
};


lang__Class *EagleAI_class();

lang__Void EagleAI___load__();
lang__Void EagleAI___defaults__(EagleAI *this);
lang__Void EagleAI___defaults___impl(EagleAI *this);
lang__Void EagleAI___destroy__(EagleAI *this);
lang__Void EagleAI___destroy___impl(EagleAI *this);
EagleAI *EagleAI_new();
lang__Void EagleAI_init(EagleAI *this);
lang__Void EagleAI_init_impl(EagleAI *this);
lang__Double EagleAI_dist(EagleAI *this, GameInfo *info, lang__Int a, lang__Int b);
lang__Double EagleAI_dist_impl(EagleAI *this, GameInfo *info, lang__Int a, lang__Int b);
lang__Void EagleAI_checkID(EagleAI *this);
lang__Void EagleAI_checkID_impl(EagleAI *this);
lang__Void EagleAI_stepImpl(EagleAI *this, GameInfo *info);
lang__Void EagleAI_stepImpl_impl(EagleAI *this, GameInfo *info);

lang__Void _EagleAI_load();

#endif // ___EagleAI__

