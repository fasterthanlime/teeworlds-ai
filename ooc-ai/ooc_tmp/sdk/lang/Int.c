/* lang.Int source file, generated with ooc */
#include "Int.h"
lang__String Int_toString(lang__Int this)
{
	lang__String str = (lang__Pointer) GC_MALLOC(((lang__SizeT) (64)));
	sprintf(str, "%d", this);
	return str;
}


lang__Bool Int_isOdd(lang__Int this)
{
	return this % 2 == 1;
}


lang__Bool Int_isEven(lang__Int this)
{
	return this % 2 == 0;
}


lang__Bool Int_in(lang__Int this, lang__Range range)
{
	return this >= range.min && this < range.max;
}



lang__Void _lang_Int_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		_lang_Object_load();
		_lang_ooclib_load();
		_lang_stdio_load();
		_lang_Range_load();
	}
}

