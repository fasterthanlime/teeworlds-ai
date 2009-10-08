/* lang.LLong source file, generated with ooc */
#include "LLong.h"
lang__String LLong_toString(lang__LLong this)
{
	lang__String str = (lang__Pointer) GC_MALLOC(((lang__SizeT) (64)));
	sprintf(str, "%lld", this);
	return str;
}


lang__String LLong_toHexString(lang__LLong this)
{
	lang__String str = (lang__Pointer) GC_MALLOC(((lang__SizeT) (64)));
	sprintf(str, "%llx", this);
	return str;
}


lang__Bool LLong_isOdd(lang__LLong this)
{
	return this % 2 == 1;
}


lang__Bool LLong_isEven(lang__LLong this)
{
	return this % 2 == 0;
}


lang__Bool LLong_in(lang__LLong this, lang__Range range)
{
	return this >= range.min && this < range.max;
}



lang__Void _lang_LLong_load()
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

