/* lang.Object source file, generated with ooc */
#include "Object.h"

lang__Void Class___defaults___impl(lang__Class *this)
{
	Object___defaults___impl((lang__Object *) this);
}

lang__Void Class___destroy___impl(lang__Class *this)
{
}

lang__Object *Class_alloc(lang__Class *this)
{
	lang__Object *object = ((lang__Object *) (lang__Pointer) GC_MALLOC(this->instanceSize));
	if (object)
	{
		object->class = this;
		Object___defaults__(object);
	}
	return object;
}

lang__Bool Class_instanceof(lang__Class *this, lang__Class *T)
{
	if (this == T)
	{
		return true;
	}
	if (this->super != NULL)
	{
		return Class_instanceof(this->super, T);
	}
	return false;
}

lang__Class *Class_class()
{
	static lang__Bool __done__ = false;
	static lang__ClassClass class = 
	{
		{
			.instanceSize = sizeof(lang__Class),
			.size = sizeof(void*),
			.name = "Class",
		},
		.__load__ = Class___load__,
		.__defaults__ = Class___defaults___impl,
		.__destroy__ = Class___destroy___impl,
		.alloc = Class_alloc,
		.instanceof = Class_instanceof,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


lang__Void Class___defaults__(lang__Class *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void Class___destroy__(lang__Class *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void Class___load__()
{
}



lang__Void Object___defaults___impl(lang__Object *this)
{
}

lang__Void Object___destroy___impl(lang__Object *this)
{
}

lang__Class *Object_class()
{
	static lang__ObjectClass class = 
	{
		{
			.instanceSize = sizeof(lang__Object),
			.size = sizeof(void*),
			.name = "Object",
		},
		.__load__ = Object___load__,
		.__defaults__ = Object___defaults___impl,
		.__destroy__ = Object___destroy___impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	return classPtr;
}


lang__Void Object___defaults__(lang__Object *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void Object___destroy__(lang__Object *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void Object___load__()
{
}



lang__Void _lang_Object_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		Class___load__();
		Object___load__();
		_lang_ooclib_load();
	}
}

