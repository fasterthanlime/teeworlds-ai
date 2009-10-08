/* lang.stdio header file, generated with ooc */
#ifndef ___lang_stdio__
#define ___lang_stdio__


#include <stdio.h>
typedef FILE *lang__FStream;

#include <sdk/lang/Object.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/String.h>
#include <sdk/lang/Exception.h>

;
lang__Class *FILE_class();
lang__Class *FStream_class();
lang__Char FStream_readChar(lang__FStream this);
lang__String FStream_readLine(lang__FStream this);
lang__Void FStream_write_chr(lang__FStream this, lang__Char chr);
lang__Void FStream_write(lang__FStream this, lang__String str);
lang__Void FStream_write_precise(lang__FStream this, lang__Char *str, lang__SizeT offset, lang__SizeT length);
lang__Void println_withStr(lang__String str);
lang__Void println();
lang__Void _lang_stdio_load();

#endif // ___lang_stdio__

