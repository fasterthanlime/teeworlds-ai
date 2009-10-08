/* lang.TypeInfo header file, generated with ooc */
#ifndef ___lang_TypeInfo__
#define ___lang_TypeInfo__


typedef struct _lang__TypeInfo lang__TypeInfo;

#include <sdk/lang/Object.h>
#include <sdk/lang/ooclib.h>
#include <sdk/structs/Array.h>
#include <sdk/text/StringBuffer.h>
struct _lang__TypeInfo 
{
	lang__Class *clazz;
	structs__Array *params;
};

lang__Class *TypeInfo_class();
lang__TypeInfo TypeInfo_new(lang__Class *clazz);
lang__String TypeInfo_toString(lang__TypeInfo this);
lang__Void _lang_TypeInfo_load();

#endif // ___lang_TypeInfo__

