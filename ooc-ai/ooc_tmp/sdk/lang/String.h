/* lang.String header file, generated with ooc */
#ifndef ___lang_String__
#define ___lang_String__


#include <stdlib.h>
#include <string.h>

#include <sdk/lang/Object.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/Int.h>
#include <sdk/lang/Bool.h>
#include <sdk/lang/LLong.h>
#include <sdk/lang/Double.h>
#include <sdk/lang/Range.h>
#include <sdk/lang/stdio.h>

lang__String String_new(lang__SizeT length);
lang__Bool String_equals(lang__String this, lang__String other);
lang__Bool String_isEmpty(lang__String this);
lang__Bool String_startsWith(lang__String this, lang__String s);
lang__Bool String_endsWith(lang__String this, lang__String s);
lang__SizeT String_indexOf(lang__String this, lang__Char c);
lang__String String_trim_space(lang__String this);
lang__String String_trim(lang__String this, lang__Char c);
lang__SizeT String_first(lang__String this);
lang__SizeT String_lastIndex(lang__String this);
lang__SizeT String_last(lang__String this);
lang__SizeT String_lastIndexOf(lang__String this, lang__Char c);
lang__String String_substring_tillEnd(lang__String this, lang__SizeT start);
lang__String String_substring(lang__String this, lang__SizeT start, lang__SizeT end);
lang__String String_reverse(lang__String this);
lang__Void String_print(lang__String this);
lang__Void String_println(lang__String this);
lang__String String_times(lang__String this, lang__Int count);
lang__String String_clone(lang__String this);
lang__String String_append(lang__String this, lang__String other);
lang__String String_append_char(lang__String this, lang__Char other);
lang__String String_prepend(lang__String this, lang__String other);
lang__String String_prepend_char(lang__String this, lang__Char other);
lang__Char String_charAt(lang__String this, lang__SizeT index);
lang__Char __OP_IDX_String_SizeT__Char(lang__String string, lang__SizeT index);
lang__String __OP_MUL_String_Int__String(lang__String str, lang__Int count);
lang__String __OP_ADD_String_String__String(lang__String left, lang__String right);
lang__String __OP_ADD_LLong_String__String(lang__LLong left, lang__String right);
lang__String __OP_ADD_String_LLong__String(lang__String left, lang__LLong right);
lang__String __OP_ADD_Int_String__String(lang__Int left, lang__String right);
lang__String __OP_ADD_String_Int__String(lang__String left, lang__Int right);
lang__String __OP_ADD_Bool_String__String(lang__Bool left, lang__String right);
lang__String __OP_ADD_String_Bool__String(lang__String left, lang__Bool right);
lang__String __OP_ADD_Double_String__String(lang__Double left, lang__String right);
lang__String __OP_ADD_String_Double__String(lang__String left, lang__Double right);
lang__String __OP_ADD_String_Char__String(lang__String left, lang__Char right);
lang__String __OP_ADD_Char_String__String(lang__Char left, lang__String right);
lang__Void _lang_String_load();

#endif // ___lang_String__

