/* lang.ooclib header file, generated with ooc */
#ifndef ___lang_ooclib__
#define ___lang_ooclib__


#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdarg.h>
#include <memory.h>
#include <gc/gc.h>
#include <string.h>
typedef char lang__Char;
typedef unsigned char lang__UChar;
typedef wchar_t lang__WChar;
typedef char *lang__String;
typedef void *lang__Pointer;
typedef int lang__Int;
typedef unsigned int lang__UInt;
typedef short lang__Short;
typedef unsigned short lang__UShort;
typedef long lang__Long;
typedef unsigned long lang__ULong;
typedef long long lang__LLong;
typedef unsigned long long lang__ULLong;
typedef long double lang__LDouble;
typedef double lang__Double;
typedef float lang__Float;
typedef int8_t lang__Int8;
typedef int16_t lang__Int16;
typedef int32_t lang__Int32;
typedef int64_t lang__Int64;
typedef uint8_t lang__UInt8;
typedef uint16_t lang__UInt16;
typedef uint32_t lang__UInt32;
typedef uint64_t lang__UInt64;
typedef uint8_t lang__Octet;
typedef void lang__Void;
typedef bool lang__Bool;
typedef size_t lang__SizeT;
typedef va_list lang__VaList;

#include <sdk/lang/Object.h>

lang__Class *Char_class();
lang__Class *UChar_class();
lang__Class *WChar_class();
lang__Class *String_class();
lang__Class *Pointer_class();
lang__Class *Int_class();
lang__Class *UInt_class();
lang__Class *Short_class();
lang__Class *UShort_class();
lang__Class *Long_class();
lang__Class *ULong_class();
lang__Class *LLong_class();
lang__Class *ULLong_class();
lang__Class *LDouble_class();
lang__Class *Double_class();
lang__Class *Float_class();
lang__Class *Int8_class();
lang__Class *Int16_class();
lang__Class *Int32_class();
lang__Class *Int64_class();
lang__Class *UInt8_class();
lang__Class *UInt16_class();
lang__Class *UInt32_class();
lang__Class *UInt64_class();
lang__Class *Octet_class();
lang__Class *Bool_class();
lang__Class *SizeT_class();
lang__Class *VaList_class();
lang__Pointer gc_calloc(lang__SizeT nmemb, lang__SizeT size);
lang__Void _lang_ooclib_load();

#endif // ___lang_ooclib__

