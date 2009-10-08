/* text.StringBuffer source file, generated with ooc */
#include "StringBuffer.h"

lang__Void StringBuffer___defaults___impl(text__StringBuffer *this)
{
	Object___defaults___impl((lang__Object *) this);
}

lang__Void StringBuffer___destroy___impl(text__StringBuffer *this)
{
}

lang__Void StringBuffer_init_impl(text__StringBuffer *this)
{
	StringBuffer_init_withCapa((text__StringBuffer *) this, ((lang__SizeT) (128)));
}

lang__Void StringBuffer_init_withCapa_impl(text__StringBuffer *this, lang__SizeT capacity)
{
	this->capacity = capacity;
	this->data = (lang__Pointer) GC_MALLOC(capacity);
	this->size = 0;
}

lang__Void StringBuffer_append_str_impl(text__StringBuffer *this, lang__String str)
{
	lang__SizeT length = (lang__SizeT) strlen(str);
	StringBuffer_checkLength(this, this->size + length);
	memcpy(((lang__Pointer) (__OP_ADD_String_LLong__String(this->data, ((lang__LLong) this->size)))), ((lang__Pointer) (str)), length);
	this->size += length;
}

lang__Void StringBuffer_append_chr_impl(text__StringBuffer *this, lang__Char chr)
{
	StringBuffer_checkLength(this, this->size + 1);
	this->data[this->size] = chr;
	this->size += 1;
}

lang__Void StringBuffer_checkLength_impl(text__StringBuffer *this, lang__SizeT min)
{
	if (min >= this->capacity)
	{
		lang__SizeT newCapa = min * 1.2 + 10;
		lang__Pointer tmp = (lang__Pointer) GC_REALLOC(((lang__Pointer) (this->data)), newCapa);
		if (!tmp)
		{
			Exception_throw(Exception_new(StringBuffer_class(), __OP_ADD_String_LLong__String("Couldn\'t allocate enough memory for StringBuffer to grow to capacity ", ((lang__LLong) newCapa))));
		}
		this->data = tmp;
		this->capacity = newCapa;
	}
}

lang__String StringBuffer_toString_impl(text__StringBuffer *this)
{
	this->data[this->capacity] = '\0';
	return this->data;
}

lang__Class *StringBuffer_class()
{
	static lang__Bool __done__ = false;
	static text__StringBufferClass class = 
	{
		{
			{
				.instanceSize = sizeof(text__StringBuffer),
				.size = sizeof(void*),
				.name = "StringBuffer",
			},
			.__load__ = (lang__Void (*)()) StringBuffer___load__,
			.__defaults__ = (lang__Void (*)(lang__Object *)) StringBuffer___defaults___impl,
			.__destroy__ = (lang__Void (*)(lang__Object *)) StringBuffer___destroy___impl,
		},
		.new = StringBuffer_new,
		.init = StringBuffer_init_impl,
		.new_withCapa = StringBuffer_new_withCapa,
		.init_withCapa = StringBuffer_init_withCapa_impl,
		.append_str = StringBuffer_append_str_impl,
		.append_chr = StringBuffer_append_chr_impl,
		.checkLength = StringBuffer_checkLength_impl,
		.toString = StringBuffer_toString_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


lang__Void StringBuffer___defaults__(text__StringBuffer *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void StringBuffer___destroy__(text__StringBuffer *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void StringBuffer_init(text__StringBuffer *this)
{
	((text__StringBufferClass *)((lang__Object *)this)->class)->init((text__StringBuffer *) this);
}


lang__Void StringBuffer_init_withCapa(text__StringBuffer *this, lang__SizeT capacity)
{
	((text__StringBufferClass *)((lang__Object *)this)->class)->init_withCapa((text__StringBuffer *) this, capacity);
}


lang__Void StringBuffer_append_str(text__StringBuffer *this, lang__String str)
{
	((text__StringBufferClass *)((lang__Object *)this)->class)->append_str((text__StringBuffer *) this, str);
}


lang__Void StringBuffer_append_chr(text__StringBuffer *this, lang__Char chr)
{
	((text__StringBufferClass *)((lang__Object *)this)->class)->append_chr((text__StringBuffer *) this, chr);
}


lang__Void StringBuffer_checkLength(text__StringBuffer *this, lang__SizeT min)
{
	((text__StringBufferClass *)((lang__Object *)this)->class)->checkLength((text__StringBuffer *) this, min);
}


lang__String StringBuffer_toString(text__StringBuffer *this)
{
	return (lang__String)((text__StringBufferClass *)((lang__Object *)this)->class)->toString((text__StringBuffer *) this);
}


lang__Void StringBuffer___load__()
{
}


text__StringBuffer *StringBuffer_new()
{
	text__StringBuffer *this = ((text__StringBuffer *) Class_alloc(StringBuffer_class()));
	StringBuffer_init(this);
	return this;
}


text__StringBuffer *StringBuffer_new_withCapa(lang__SizeT capacity)
{
	text__StringBuffer *this = ((text__StringBuffer *) Class_alloc(StringBuffer_class()));
	StringBuffer_init_withCapa(this, capacity);
	return this;
}



lang__Void _text_StringBuffer_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		StringBuffer___load__();
		_lang_Iterator_load();
		_lang_String_load();
		_lang_Float_load();
		_lang_Interface_load();
		_lang_Range_load();
		_lang_Object_load();
		_lang_TypeInfo_load();
		_lang_Double_load();
		_lang_Exception_load();
		_lang_Char_load();
		_lang_ooclib_load();
		_lang_Bool_load();
		_lang_stdio_load();
		_lang_Iterable_load();
		_lang_Int_load();
		_lang_LLong_load();
	}
}

