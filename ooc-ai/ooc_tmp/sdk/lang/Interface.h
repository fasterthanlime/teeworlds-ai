/* lang.Interface header file, generated with ooc */
#ifndef ___lang_Interface__
#define ___lang_Interface__


struct _lang__Interface;
typedef struct _lang__Interface lang__Interface;
struct _lang__InterfaceClass;
typedef struct _lang__InterfaceClass lang__InterfaceClass;

#include <sdk/lang/Object.h>
#include <sdk/lang/ooclib.h>

struct _lang__Interface
{
	struct _lang__Object __super__;
	lang__Object *realThis;
	lang__Object *funcs;
};


struct _lang__InterfaceClass
{
	struct _lang__ObjectClass __super__;
	lang__Interface * (*new)(lang__Object *, lang__Object *);
	lang__Void (*init)(lang__Interface *, lang__Object *, lang__Object *);
};


lang__Class *Interface_class();

lang__Void Interface___load__();
lang__Void Interface___defaults__(lang__Interface *this);
lang__Void Interface___defaults___impl(lang__Interface *this);
lang__Void Interface___destroy__(lang__Interface *this);
lang__Void Interface___destroy___impl(lang__Interface *this);
lang__Interface *Interface_new(lang__Object *realThis, lang__Object *funcs);
lang__Void Interface_init(lang__Interface *this, lang__Object *realThis, lang__Object *funcs);
lang__Void Interface_init_impl(lang__Interface *this, lang__Object *realThis, lang__Object *funcs);

lang__Void _lang_Interface_load();

#endif // ___lang_Interface__

