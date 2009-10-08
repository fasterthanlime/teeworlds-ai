/* lang.String source file, generated with ooc */
#include "String.h"
lang__String String_new(lang__SizeT length)
{
	return (lang__Pointer) GC_MALLOC(length);
}



lang__Bool String_equals(lang__String this, lang__String other)
{
	if ((this == NULL) || (other == NULL))
	{
		return false;
	}
	if ((lang__SizeT) strlen(this) != (lang__SizeT) strlen(other))
	{
		return false;
	}
	
	{
		lang__SizeT i;
		for (i = 0; i < (lang__SizeT) strlen(other); i++)
		{
			if (__OP_IDX_String_SizeT__Char(this, i) != __OP_IDX_String_SizeT__Char(other, i))
			{
				return false;
			}
		}
	};
	return true;
}







lang__Bool String_isEmpty(lang__String this)
{
	return (this == NULL) || (this[0] == 0);
}


lang__Bool String_startsWith(lang__String this, lang__String s)
{
	if ((lang__SizeT) strlen(this) < (lang__SizeT) strlen(s))
	{
		return false;
	}
	
	{
		lang__SizeT i;
		for (i = 0; i < (lang__SizeT) strlen(s); i++)
		{
			if (__OP_IDX_String_SizeT__Char(this, i) != __OP_IDX_String_SizeT__Char(s, i))
			{
				return false;
			}
		}
	};
	return true;
}


lang__Bool String_endsWith(lang__String this, lang__String s)
{
	lang__SizeT l1 = (lang__SizeT) strlen(this);
	lang__SizeT l2 = (lang__SizeT) strlen(s);
	if (l1 < l2)
	{
		return false;
	}
	lang__SizeT offset = (l1 - l2);
	
	{
		lang__SizeT i;
		for (i = 0; i < l2; i++)
		{
			if (__OP_IDX_String_SizeT__Char(this, i + offset) != __OP_IDX_String_SizeT__Char(s, i))
			{
				return false;
			}
		}
	};
	return true;
}


lang__SizeT String_indexOf(lang__String this, lang__Char c)
{
	lang__SizeT length = (lang__SizeT) strlen(this);
	
	{
		lang__SizeT i;
		for (i = 0; i < length; i++)
		{
			if (__OP_IDX_String_SizeT__Char(this, i) == c)
			{
				return i;
			}
		}
	};
	return 0 - 1;
}


lang__String String_trim_space(lang__String this)
{
	return String_trim(this, ' ');
}


lang__String String_trim(lang__String this, lang__Char c)
{
	lang__Int start = 0;
	while (this[start] == c)
	{
		start += 1;
	}
	lang__SizeT end = (lang__SizeT) strlen(this);
	while (__OP_IDX_String_SizeT__Char(this, end - 1) == c)
	{
		end -= 1;
	}
	if (start != 0 || end != (lang__SizeT) strlen(this))
	{
		return String_substring(this, start, end);
	}
	return this;
}


lang__SizeT String_first(lang__String this)
{
	return this[0];
}


lang__SizeT String_lastIndex(lang__String this)
{
	return (lang__SizeT) strlen(this) - 1;
}


lang__SizeT String_last(lang__String this)
{
	return __OP_IDX_String_SizeT__Char(this, String_lastIndex(this));
}


lang__SizeT String_lastIndexOf(lang__String this, lang__Char c)
{
	lang__SizeT i = (lang__SizeT) strlen(this);
	while (i)
	{
		if (__OP_IDX_String_SizeT__Char(this, i) == c)
		{
			return i;
		}
		i -= 1;
	}
	return 0 - 1;
}


lang__String String_substring_tillEnd(lang__String this, lang__SizeT start)
{
	lang__SizeT len = (lang__SizeT) strlen(this);
	if (start > len)
	{
		printf("String.substring~tillEnd: out of bounds: length = %zd, start = %zd\n", len, start);
		return NULL;
	}
	lang__SizeT diff = (len - start);
	lang__String sub = ((lang__String) (lang__Pointer) GC_MALLOC(diff + 1));
	sub[diff + 1] = 0;
	memcpy(((lang__Pointer) (sub)), ((lang__Pointer) (((lang__Char *) this) + start)), diff);
	return sub;
}


lang__String String_substring(lang__String this, lang__SizeT start, lang__SizeT end)
{
	lang__SizeT len = (lang__SizeT) strlen(this);
	if (start > len || start > end || end > len)
	{
		printf("String.substring: out of bounds: length = %zd, start = %zd, end = %zd\n", len, start, end);
		return NULL;
	}
	lang__SizeT diff = (end - start);
	lang__String sub = ((lang__String) (lang__Pointer) GC_MALLOC(diff + 1));
	sub[diff + 1] = 0;
	memcpy(((lang__Pointer) (sub)), ((lang__Pointer) (((lang__Char *) this) + start)), diff);
	return sub;
}


lang__String String_reverse(lang__String this)
{
	lang__SizeT len = (lang__SizeT) strlen(this);
	if (!len)
	{
		return NULL;
	}
	lang__String result = ((lang__String) (lang__Pointer) GC_MALLOC(len + 1));
	
	{
		lang__SizeT i;
		for (i = 0; i < len; i++)
		{
			result[i] = this[(len - 1) - i];
		}
	};
	result[len] = 0;
	return result;
}


lang__Void String_print(lang__String this)
{
	printf("%s", this);
	fflush(stdout);
}


lang__Void String_println(lang__String this)
{
	printf("%s\n", this);
}


lang__String String_times(lang__String this, lang__Int count)
{
	lang__SizeT length = (lang__SizeT) strlen(this);
	lang__Char *result = ((lang__Char *) (lang__Pointer) GC_MALLOC((length * count) + 1));
	
	{
		lang__Int i;
		for (i = 0; i < count; i++)
		{
			memcpy(((lang__Pointer) (result + (i * length))), ((lang__Pointer) (this)), length);
		}
	};
	result[length * count] = '\0';
	return result;
}


lang__String String_clone(lang__String this)
{
	lang__SizeT length = (lang__SizeT) strlen(this);
	lang__Pointer copy = (lang__Pointer) GC_MALLOC(length + 1);
	memcpy(copy, ((lang__Pointer) (this)), length + 1);
	return copy;
}


lang__String String_append(lang__String this, lang__String other)
{
	lang__SizeT length = (lang__SizeT) strlen(this);
	lang__SizeT rlength = (lang__SizeT) strlen(other);
	lang__Char *copy = ((lang__Char *) (lang__Pointer) GC_MALLOC(length + rlength + 1));
	memcpy(((lang__Pointer) (copy)), ((lang__Pointer) (this)), length);
	memcpy(((lang__Pointer) (((lang__Char *) copy) + length)), ((lang__Pointer) (other)), rlength + 1);
	return copy;
}


lang__String String_append_char(lang__String this, lang__Char other)
{
	lang__SizeT length = (lang__SizeT) strlen(this);
	lang__Char *copy = ((lang__Char *) (lang__Pointer) GC_MALLOC(length + 2));
	memcpy(((lang__Pointer) (copy)), ((lang__Pointer) (this)), length);
	((lang__Char *) copy)[length - 1] = other;
	return copy;
}


lang__String String_prepend(lang__String this, lang__String other)
{
	return String_append(other, this);
}


lang__String String_prepend_char(lang__String this, lang__Char other)
{
	lang__SizeT length = (lang__SizeT) strlen(this);
	lang__Char *copy = ((lang__Char *) (lang__Pointer) GC_MALLOC(length + 2));
	((lang__Char *) copy)[0] = other;
	memcpy(((lang__Pointer) (copy + 1)), ((lang__Pointer) (this)), length);
	return copy;
}


lang__Char String_charAt(lang__String this, lang__SizeT index)
{
	return ((lang__Char *) this)[index];
}


lang__Char __OP_IDX_String_SizeT__Char(lang__String string, lang__SizeT index)
{
	return String_charAt(string, index);
}

lang__String __OP_MUL_String_Int__String(lang__String str, lang__Int count)
{
	return String_times(str, count);
}

lang__String __OP_ADD_String_String__String(lang__String left, lang__String right)
{
	return String_append(left, right);
}

lang__String __OP_ADD_LLong_String__String(lang__LLong left, lang__String right)
{
	return __OP_ADD_String_String__String(LLong_toString(left), right);
}

lang__String __OP_ADD_String_LLong__String(lang__String left, lang__LLong right)
{
	return __OP_ADD_String_String__String(left, LLong_toString(right));
}

lang__String __OP_ADD_Int_String__String(lang__Int left, lang__String right)
{
	return __OP_ADD_String_String__String(Int_toString(left), right);
}

lang__String __OP_ADD_String_Int__String(lang__String left, lang__Int right)
{
	return __OP_ADD_String_String__String(left, Int_toString(right));
}

lang__String __OP_ADD_Bool_String__String(lang__Bool left, lang__String right)
{
	return __OP_ADD_String_String__String(Bool_toString(left), right);
}

lang__String __OP_ADD_String_Bool__String(lang__String left, lang__Bool right)
{
	return __OP_ADD_String_String__String(left, Bool_toString(right));
}

lang__String __OP_ADD_Double_String__String(lang__Double left, lang__String right)
{
	return __OP_ADD_String_String__String(Double_toString(left), right);
}

lang__String __OP_ADD_String_Double__String(lang__String left, lang__Double right)
{
	return __OP_ADD_String_String__String(left, Double_toString(right));
}

lang__String __OP_ADD_String_Char__String(lang__String left, lang__Char right)
{
	return String_append_char(left, right);
}

lang__String __OP_ADD_Char_String__String(lang__Char left, lang__String right)
{
	return String_prepend_char(right, left);
}


lang__Void _lang_String_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		_lang_Object_load();
		_lang_ooclib_load();
		_lang_Int_load();
		_lang_Bool_load();
		_lang_LLong_load();
		_lang_Double_load();
		_lang_Range_load();
		_lang_stdio_load();
	}
}

