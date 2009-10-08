/* lang.Iterable source file, generated with ooc */
#include "Iterable.h"

lang__Void Iterable___defaults___impl(lang__Iterable *this)
{
	Object___defaults___impl((lang__Object *) this);
}

lang__Void Iterable___destroy___impl(lang__Iterable *this)
{
}

lang__Class *Iterable_class()
{
	static lang__Bool __done__ = false;
	static lang__IterableClass class = 
	{
		{
			{
				.instanceSize = sizeof(lang__Iterable),
				.size = sizeof(void*),
				.name = "Iterable",
			},
			.__load__ = (lang__Void (*)()) Iterable___load__,
			.__defaults__ = (lang__Void (*)(lang__Object *)) Iterable___defaults___impl,
			.__destroy__ = (lang__Void (*)(lang__Object *)) Iterable___destroy___impl,
		},
		.iterator = Iterable_iterator,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


lang__Void Iterable___defaults__(lang__Iterable *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void Iterable___destroy__(lang__Iterable *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Iterator *Iterable_iterator(lang__Iterable *this)
{
	return (lang__Iterator *)((lang__IterableClass *)((lang__Object *)this)->class)->iterator((lang__Iterable *) this);
}


lang__Void Iterable___load__()
{
}



lang__Void _lang_Iterable_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		Iterable___load__();
		_lang_Object_load();
		_lang_ooclib_load();
		_lang_Iterator_load();
	}
}

