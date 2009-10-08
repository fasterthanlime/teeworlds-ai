/* lang.Double source file, generated with ooc */
#include "Double.h"
lang__String Double_toString(lang__Double this)
{
	lang__String str = (lang__Pointer) GC_MALLOC(((lang__SizeT) (64)));
	sprintf(str, "%.2f", this);
	return str;
}


lang__Double Double_abs(lang__Double this)
{
	return this < 0 ? 0 - this : this;
}



lang__Void _lang_Double_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		_lang_Object_load();
		_lang_ooclib_load();
		_lang_stdio_load();
	}
}

