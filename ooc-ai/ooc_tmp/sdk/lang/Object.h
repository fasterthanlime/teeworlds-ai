/* lang.Object header file, generated with ooc */
#ifndef ___lang_Object__
#define ___lang_Object__


struct _lang__Class;
typedef struct _lang__Class lang__Class;
struct _lang__ClassClass;
typedef struct _lang__ClassClass lang__ClassClass;
struct _lang__Object;
typedef struct _lang__Object lang__Object;
struct _lang__ObjectClass;
typedef struct _lang__ObjectClass lang__ObjectClass;

#include <sdk/lang/ooclib.h>

struct _lang__Class
{
	lang__Class *class;
	lang__SizeT instanceSize;
	lang__SizeT size;
	lang__String name;
	lang__Class *super;
};


struct _lang__ClassClass
{
	struct _lang__Class __super__;
	lang__Object * (*alloc)(lang__Class *);
	lang__Bool (*instanceof)(lang__Class *, lang__Class *);
	lang__Void (*__defaults__)(lang__Class *);
	lang__Void (*__destroy__)(lang__Class *);
	lang__Void (*__load__)();
};


lang__Class *Class_class();

lang__Void Class___load__();
lang__Void Class___defaults__(lang__Class *this);
lang__Void Class___defaults___impl(lang__Class *this);
lang__Void Class___destroy__(lang__Class *this);
lang__Void Class___destroy___impl(lang__Class *this);
lang__Object *Class_alloc(lang__Class *this);
lang__Bool Class_instanceof(lang__Class *this, lang__Class *T);

struct _lang__Object
{
	
	lang__Class *class;
};


struct _lang__ObjectClass
{
	struct _lang__Class __super__;
	lang__Void (*__load__)();
	lang__Void (*__defaults__)(lang__Object *);
	lang__Void (*__destroy__)(lang__Object *);
};


lang__Class *Object_class();

lang__Void Object___load__();
lang__Void Object___defaults__(lang__Object *this);
lang__Void Object___defaults___impl(lang__Object *this);
lang__Void Object___destroy__(lang__Object *this);
lang__Void Object___destroy___impl(lang__Object *this);

lang__Void _lang_Object_load();

#endif // ___lang_Object__

