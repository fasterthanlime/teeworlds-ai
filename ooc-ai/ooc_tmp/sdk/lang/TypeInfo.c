/* lang.TypeInfo source file, generated with ooc */
#include "TypeInfo.h"
lang__Class *TypeInfo_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(lang__TypeInfo);
		_class->instanceSize = sizeof(lang__TypeInfo);
		_class->name = "TypeInfo";
	}
	return _class;
}


lang__TypeInfo TypeInfo_new(lang__Class *clazz)
{
	lang__TypeInfo this;
	this.clazz = clazz;
	this.params = NULL;
	return this;
}


lang__String TypeInfo_toString(lang__TypeInfo this)
{
	text__StringBuffer *sb = StringBuffer_new();
	StringBuffer_append_str(sb, this.clazz->name);
	if (this.params)
	{
		StringBuffer_append_chr(sb, '<');
		lang__Bool isFirst = true;
		
		{
			lang__TypeInfo param;
			
			{
				lang__Iterator *iter315 = Array_iterator(this.params);
				while (Iterator_hasNext(iter315))
				{
					Iterator_next(iter315, &(param));
					StringBuffer_append_str(sb, TypeInfo_toString(param));
					if (!isFirst)
					{
						StringBuffer_append_str(sb, ", ");
					}
					else 
					{
						isFirst = false;
					}
				}
			};
		};
		StringBuffer_append_chr(sb, '>');
	}
	return StringBuffer_toString(sb);
}



lang__Void _lang_TypeInfo_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		_lang_Object_load();
		_lang_ooclib_load();
		_structs_Array_load();
		_text_StringBuffer_load();
	}
}

