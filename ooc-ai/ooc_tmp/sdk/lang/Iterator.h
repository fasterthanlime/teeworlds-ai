/* lang.Iterator header file, generated with ooc */
#ifndef ___lang_Iterator__
#define ___lang_Iterator__


struct _lang__Iterator;
typedef struct _lang__Iterator lang__Iterator;
struct _lang__IteratorClass;
typedef struct _lang__IteratorClass lang__IteratorClass;

#include <sdk/lang/Object.h>
#include <sdk/lang/ooclib.h>

struct _lang__Iterator
{
	struct _lang__Object __super__;
	lang__Class *T;
};


struct _lang__IteratorClass
{
	struct _lang__ObjectClass __super__;
	lang__Bool (*hasNext)(lang__Iterator *);
	lang__Void (*next)(lang__Iterator *, lang__Pointer);
};


lang__Class *Iterator_class();

lang__Void Iterator___load__();
lang__Void Iterator___defaults__(lang__Iterator *this);
lang__Void Iterator___defaults___impl(lang__Iterator *this);
lang__Void Iterator___destroy__(lang__Iterator *this);
lang__Void Iterator___destroy___impl(lang__Iterator *this);
lang__Bool Iterator_hasNext(lang__Iterator *this);
void Iterator_next(lang__Iterator *this, lang__Pointer returnarg8);

lang__Void _lang_Iterator_load();

#endif // ___lang_Iterator__

