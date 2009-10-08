/* lang.Iterator source file, generated with ooc */
#include "Iterator.h"

lang__Void Iterator___defaults___impl(lang__Iterator *this)
{
	Object___defaults___impl((lang__Object *) this);
}

lang__Void Iterator___destroy___impl(lang__Iterator *this)
{
}

lang__Class *Iterator_class()
{
	static lang__Bool __done__ = false;
	static lang__IteratorClass class = 
	{
		{
			{
				.instanceSize = sizeof(lang__Iterator),
				.size = sizeof(void*),
				.name = "Iterator",
			},
			.__load__ = (lang__Void (*)()) Iterator___load__,
			.__defaults__ = (lang__Void (*)(lang__Object *)) Iterator___defaults___impl,
			.__destroy__ = (lang__Void (*)(lang__Object *)) Iterator___destroy___impl,
		},
		.hasNext = Iterator_hasNext,
		.next = Iterator_next,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


lang__Void Iterator___defaults__(lang__Iterator *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void Iterator___destroy__(lang__Iterator *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Bool Iterator_hasNext(lang__Iterator *this)
{
	return (lang__Bool)((lang__IteratorClass *)((lang__Object *)this)->class)->hasNext((lang__Iterator *) this);
}


void Iterator_next(lang__Iterator *this, lang__Pointer returnarg8)
{
	((lang__IteratorClass *)((lang__Object *)this)->class)->next((lang__Iterator *) this, returnarg8);
}


lang__Void Iterator___load__()
{
}



lang__Void _lang_Iterator_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		Iterator___load__();
		_lang_Object_load();
		_lang_ooclib_load();
	}
}

