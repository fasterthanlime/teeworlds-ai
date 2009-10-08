/* lang.Bool source file, generated with ooc */
#include "Bool.h"
lang__String Bool_toString(lang__Bool this)
{
	return this ? "true" : "false";
}



lang__Void _lang_Bool_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		_lang_Object_load();
		_lang_ooclib_load();
	}
}

