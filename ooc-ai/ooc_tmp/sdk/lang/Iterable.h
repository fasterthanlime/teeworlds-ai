/* lang.Iterable header file, generated with ooc */
#ifndef ___lang_Iterable__
#define ___lang_Iterable__


struct _lang__Iterable;
typedef struct _lang__Iterable lang__Iterable;
struct _lang__IterableClass;
typedef struct _lang__IterableClass lang__IterableClass;

#include <sdk/lang/Object.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/Iterator.h>

struct _lang__Iterable
{
	struct _lang__Object __super__;
	lang__Class *T;
};


struct _lang__IterableClass
{
	struct _lang__ObjectClass __super__;
	lang__Iterator * (*iterator)(lang__Iterable *);
};


lang__Class *Iterable_class();

lang__Void Iterable___load__();
lang__Void Iterable___defaults__(lang__Iterable *this);
lang__Void Iterable___defaults___impl(lang__Iterable *this);
lang__Void Iterable___destroy__(lang__Iterable *this);
lang__Void Iterable___destroy___impl(lang__Iterable *this);
lang__Iterator *Iterable_iterator(lang__Iterable *this);

lang__Void _lang_Iterable_load();

#endif // ___lang_Iterable__

