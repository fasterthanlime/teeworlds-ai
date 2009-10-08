/* lang.ooclib source file, generated with ooc */
#include "ooclib.h"
lang__Class *Char_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Char);
		_class->instanceSize = sizeof(lang__Char);
		_class->name = "Char";
	}
	return _class;
}


lang__Class *UChar_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__UChar);
		_class->instanceSize = sizeof(lang__UChar);
		_class->name = "UChar";
	}
	return _class;
}


lang__Class *WChar_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__WChar);
		_class->instanceSize = sizeof(lang__WChar);
		_class->name = "WChar";
	}
	return _class;
}


lang__Class *String_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Pointer);
		_class->instanceSize = sizeof(lang__Pointer);
		_class->name = "String";
	}
	return _class;
}


lang__Class *Pointer_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Pointer);
		_class->instanceSize = sizeof(lang__Pointer);
		_class->name = "Pointer";
	}
	return _class;
}


lang__Class *Int_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Int);
		_class->instanceSize = sizeof(lang__Int);
		_class->name = "Int";
	}
	return _class;
}


lang__Class *UInt_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__UInt);
		_class->instanceSize = sizeof(lang__UInt);
		_class->name = "UInt";
	}
	return _class;
}


lang__Class *Short_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Short);
		_class->instanceSize = sizeof(lang__Short);
		_class->name = "Short";
	}
	return _class;
}


lang__Class *UShort_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__UShort);
		_class->instanceSize = sizeof(lang__UShort);
		_class->name = "UShort";
	}
	return _class;
}


lang__Class *Long_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Long);
		_class->instanceSize = sizeof(lang__Long);
		_class->name = "Long";
	}
	return _class;
}


lang__Class *ULong_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__ULong);
		_class->instanceSize = sizeof(lang__ULong);
		_class->name = "ULong";
	}
	return _class;
}


lang__Class *LLong_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__LLong);
		_class->instanceSize = sizeof(lang__LLong);
		_class->name = "LLong";
	}
	return _class;
}


lang__Class *ULLong_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__ULLong);
		_class->instanceSize = sizeof(lang__ULLong);
		_class->name = "ULLong";
	}
	return _class;
}


lang__Class *LDouble_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__LDouble);
		_class->instanceSize = sizeof(lang__LDouble);
		_class->name = "LDouble";
	}
	return _class;
}


lang__Class *Double_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Double);
		_class->instanceSize = sizeof(lang__Double);
		_class->name = "Double";
	}
	return _class;
}


lang__Class *Float_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Float);
		_class->instanceSize = sizeof(lang__Float);
		_class->name = "Float";
	}
	return _class;
}


lang__Class *Int8_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Int8);
		_class->instanceSize = sizeof(lang__Int8);
		_class->name = "Int8";
	}
	return _class;
}


lang__Class *Int16_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Int16);
		_class->instanceSize = sizeof(lang__Int16);
		_class->name = "Int16";
	}
	return _class;
}


lang__Class *Int32_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Int32);
		_class->instanceSize = sizeof(lang__Int32);
		_class->name = "Int32";
	}
	return _class;
}


lang__Class *Int64_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Int64);
		_class->instanceSize = sizeof(lang__Int64);
		_class->name = "Int64";
	}
	return _class;
}


lang__Class *UInt8_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__UInt8);
		_class->instanceSize = sizeof(lang__UInt8);
		_class->name = "UInt8";
	}
	return _class;
}


lang__Class *UInt16_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__UInt16);
		_class->instanceSize = sizeof(lang__UInt16);
		_class->name = "UInt16";
	}
	return _class;
}


lang__Class *UInt32_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__UInt32);
		_class->instanceSize = sizeof(lang__UInt32);
		_class->name = "UInt32";
	}
	return _class;
}


lang__Class *UInt64_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__UInt64);
		_class->instanceSize = sizeof(lang__UInt64);
		_class->name = "UInt64";
	}
	return _class;
}


lang__Class *Octet_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Octet);
		_class->instanceSize = sizeof(lang__Octet);
		_class->name = "Octet";
	}
	return _class;
}


lang__Class *Bool_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__Bool);
		_class->instanceSize = sizeof(lang__Bool);
		_class->name = "Bool";
	}
	return _class;
}


lang__Class *SizeT_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__SizeT);
		_class->instanceSize = sizeof(lang__SizeT);
		_class->name = "SizeT";
	}
	return _class;
}


lang__Class *VaList_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__VaList);
		_class->instanceSize = sizeof(lang__VaList);
		_class->name = "VaList";
	}
	return _class;
}


lang__Pointer gc_calloc(lang__SizeT nmemb, lang__SizeT size)
{
	return (lang__Pointer) GC_MALLOC(nmemb * size);
}


lang__Void _lang_ooclib_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		_lang_Object_load();
	}
}

