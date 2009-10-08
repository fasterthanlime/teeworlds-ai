/* lang.Char header file, generated with ooc */
#ifndef ___lang_Char__
#define ___lang_Char__


#include <ctype.h>

#include <sdk/lang/Object.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/stdio.h>

lang__Bool Char_isAlphaNumeric(lang__Char this);
lang__Bool Char_isAlpha(lang__Char this);
lang__Bool Char_isDigit(lang__Char this);
lang__Bool Char_isWhitespace(lang__Char this);
lang__Char Char_toLower(lang__Char this);
lang__Int Char_toInt(lang__Char this);
lang__Void Char_print(lang__Char this);
lang__Void Char_println(lang__Char this);
lang__Void _lang_Char_load();

#endif // ___lang_Char__

