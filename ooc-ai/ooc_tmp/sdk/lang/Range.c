/* lang.Range source file, generated with ooc */
#include "Range.h"
lang__Class *Range_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Range);
		_class->instanceSize = sizeof(lang__Range);
		_class->name = "Range";
	}
	return _class;
}


lang__Range Range_new(lang__Int min, lang__Int max)
{
	lang__Range this;
	this.min = min;
	this.max = max;
	return this;
}



lang__Void _lang_Range_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		_lang_Object_load();
		_lang_ooclib_load();
		_lang_Int_load();
	}
}

