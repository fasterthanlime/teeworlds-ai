/* lang.Exception header file, generated with ooc */
#ifndef ___lang_Exception__
#define ___lang_Exception__


struct _lang__Exception;
typedef struct _lang__Exception lang__Exception;
struct _lang__ExceptionClass;
typedef struct _lang__ExceptionClass lang__ExceptionClass;

#include <sdk/lang/Object.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>

struct _lang__Exception
{
	struct _lang__Object __super__;
	lang__Class *origin;
	lang__String msg;
};


struct _lang__ExceptionClass
{
	struct _lang__ObjectClass __super__;
	lang__Exception * (*new)(lang__Class *, lang__String);
	lang__Void (*init)(lang__Exception *, lang__Class *, lang__String);
	lang__Exception * (*new_noOrigin)(lang__String);
	lang__Void (*init_noOrigin)(lang__Exception *, lang__String);
	lang__Void (*crash)(lang__Exception *);
	lang__String (*getMessage)(lang__Exception *);
	lang__Void (*print)(lang__Exception *);
	lang__Void (*throw)(lang__Exception *);
};


lang__Class *Exception_class();

lang__Void Exception___load__();
lang__Void Exception___defaults__(lang__Exception *this);
lang__Void Exception___defaults___impl(lang__Exception *this);
lang__Void Exception___destroy__(lang__Exception *this);
lang__Void Exception___destroy___impl(lang__Exception *this);
lang__Exception *Exception_new(lang__Class *origin, lang__String msg);
lang__Void Exception_init(lang__Exception *this, lang__Class *origin, lang__String msg);
lang__Void Exception_init_impl(lang__Exception *this, lang__Class *origin, lang__String msg);
lang__Exception *Exception_new_noOrigin(lang__String msg);
lang__Void Exception_init_noOrigin(lang__Exception *this, lang__String msg);
lang__Void Exception_init_noOrigin_impl(lang__Exception *this, lang__String msg);
lang__Void Exception_crash(lang__Exception *this);
lang__Void Exception_crash_impl(lang__Exception *this);
lang__String Exception_getMessage(lang__Exception *this);
lang__String Exception_getMessage_impl(lang__Exception *this);
lang__Void Exception_print(lang__Exception *this);
lang__Void Exception_print_impl(lang__Exception *this);
lang__Void Exception_throw(lang__Exception *this);
lang__Void Exception_throw_impl(lang__Exception *this);

lang__Void _lang_Exception_load();

#endif // ___lang_Exception__

