/* lang.Interface source file, generated with ooc */
#include "Interface.h"

lang__Void Interface___defaults___impl(lang__Interface *this)
{
	Object___defaults___impl((lang__Object *) this);
}

lang__Void Interface___destroy___impl(lang__Interface *this)
{
}

lang__Void Interface_init_impl(lang__Interface *this, lang__Object *realThis, lang__Object *funcs)
{
	this->funcs = funcs;
	this->realThis = realThis;
}

lang__Class *Interface_class()
{
	static lang__Bool __done__ = false;
	static lang__InterfaceClass class = 
	{
		{
			{
				.instanceSize = sizeof(lang__Interface),
				.size = sizeof(void*),
				.name = "Interface",
			},
			.__load__ = (lang__Void (*)()) Interface___load__,
			.__defaults__ = (lang__Void (*)(lang__Object *)) Interface___defaults___impl,
			.__destroy__ = (lang__Void (*)(lang__Object *)) Interface___destroy___impl,
		},
		.new = Interface_new,
		.init = Interface_init_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


lang__Void Interface___defaults__(lang__Interface *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void Interface___destroy__(lang__Interface *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void Interface_init(lang__Interface *this, lang__Object *realThis, lang__Object *funcs)
{
	((lang__InterfaceClass *)((lang__Object *)this)->class)->init((lang__Interface *) this, realThis, funcs);
}


lang__Void Interface___load__()
{
}


lang__Interface *Interface_new(lang__Object *realThis, lang__Object *funcs)
{
	lang__Interface *this = ((lang__Interface *) Class_alloc(Interface_class()));
	Interface_init(this, realThis, funcs);
	return this;
}



lang__Void _lang_Interface_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		Interface___load__();
		_lang_Object_load();
		_lang_ooclib_load();
	}
}

