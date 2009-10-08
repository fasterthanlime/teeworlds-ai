/* structs.Array source file, generated with ooc */
#include "Array.h"

lang__Void Array___defaults___impl(structs__Array *this)
{
	Iterable___defaults___impl((lang__Iterable *) this);
}

lang__Void Array___destroy___impl(structs__Array *this)
{
}

lang__Void Array_init_impl(structs__Array *this, lang__SizeT size)
{
	this->size = size;
	lang__Pointer genref313 = gc_calloc(size, Pointer_class()->size);
	this->data = genref313;
}

lang__Void Array_init_withData_impl(structs__Array *this, lang__Pointer data, lang__SizeT size)
{
	this->size = size;
	lang__Pointer genref314 = gc_calloc(size, this->T->size);
	this->data = genref314;
	memcpy(((lang__Pointer) (this->data)), data, size * this->T->size);
}

void Array_get_impl(structs__Array *this, lang__Pointer returnarg214, lang__Int i)
{
	if (i < 0 || i >= this->size)
	{
		Exception_throw(Exception_new(Array_class(), String_append(String_append(String_append(String_append("Attempting to access an array of size ", Int_toString(((lang__Int) this->size))), " at index "), Int_toString(i)), "\n")));
	}
	if (returnarg214)
	{
		memcpy(returnarg214, ((lang__Pointer) (this->data + i * this->T->size)), this->T->size);
	}
	return;
}

lang__Void Array_set_impl(structs__Array *this, lang__Int i, uint8_t * value)
{
	if (i < 0 || i >= this->size)
	{
		Exception_throw(Exception_new(Array_class(), String_append(String_append(String_append(String_append("Attempting to set the value of an array of size ", Int_toString(((lang__Int) this->size))), " at index "), Int_toString(i)), "\n")));
	}
	memcpy(((lang__Pointer) (this->data + i * this->T->size)), ((lang__Pointer) (value)), this->T->size);
}

lang__Int Array_size_impl(structs__Array *this)
{
	return this->size;
}

lang__Iterator *Array_iterator_impl(structs__Array *this)
{
	return ((lang__Iterator *) ArrayIterator_new(this->T, this));
}

lang__SizeT Array_lastIndex_impl(structs__Array *this)
{
	return this->size - 1;
}

lang__Bool Array_isEmpty_impl(structs__Array *this)
{
	return this->size == 0;
}

lang__Void Array_each_impl(structs__Array *this, void (*f)(uint8_t *))
{
	
	{
		lang__Int i;
		for (i = 0; i < this->size; i++)
		{
			lang__Class *val;
			Array_get(this, &(val), i);
			f(((uint8_t *) (val)));
		}
	};
}

lang__Class *Array_class()
{
	static lang__Bool __done__ = false;
	static structs__ArrayClass class = 
	{
		{
			{
				{
					.instanceSize = sizeof(structs__Array),
					.size = sizeof(void*),
					.name = "Array",
				},
				.__load__ = (lang__Void (*)()) Array___load__,
				.__defaults__ = (lang__Void (*)(lang__Object *)) Array___defaults___impl,
				.__destroy__ = (lang__Void (*)(lang__Object *)) Array___destroy___impl,
			},
			.iterator = (lang__Iterator * (*)(lang__Iterable *)) Array_iterator_impl,
		},
		.new = Array_new,
		.init = Array_init_impl,
		.new_withData = Array_new_withData,
		.init_withData = Array_init_withData_impl,
		.get = Array_get_impl,
		.set = Array_set_impl,
		.size = Array_size_impl,
		.lastIndex = Array_lastIndex_impl,
		.isEmpty = Array_isEmpty_impl,
		.each = Array_each_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Iterable_class();
	}
	return classPtr;
}


lang__Void Array___defaults__(structs__Array *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void Array___destroy__(structs__Array *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void Array_init(structs__Array *this, lang__SizeT size)
{
	((structs__ArrayClass *)((lang__Object *)this)->class)->init((structs__Array *) this, size);
}


lang__Void Array_init_withData(structs__Array *this, lang__Pointer data, lang__SizeT size)
{
	((structs__ArrayClass *)((lang__Object *)this)->class)->init_withData((structs__Array *) this, data, size);
}


void Array_get(structs__Array *this, lang__Pointer returnarg214, lang__Int i)
{
	((structs__ArrayClass *)((lang__Object *)this)->class)->get((structs__Array *) this, returnarg214, i);
}


lang__Void Array_set(structs__Array *this, lang__Int i, uint8_t * value)
{
	((structs__ArrayClass *)((lang__Object *)this)->class)->set((structs__Array *) this, i, value);
}


lang__Int Array_size(structs__Array *this)
{
	return (lang__Int)((structs__ArrayClass *)((lang__Object *)this)->class)->size((structs__Array *) this);
}


lang__Iterator *Array_iterator(structs__Array *this)
{
	return (lang__Iterator *)((lang__IterableClass *)((lang__Object *)this)->class)->iterator((lang__Iterable *) this);
}


lang__SizeT Array_lastIndex(structs__Array *this)
{
	return (lang__SizeT)((structs__ArrayClass *)((lang__Object *)this)->class)->lastIndex((structs__Array *) this);
}


lang__Bool Array_isEmpty(structs__Array *this)
{
	return (lang__Bool)((structs__ArrayClass *)((lang__Object *)this)->class)->isEmpty((structs__Array *) this);
}


lang__Void Array_each(structs__Array *this, void (*f)(uint8_t *))
{
	((structs__ArrayClass *)((lang__Object *)this)->class)->each((structs__Array *) this, f);
}


lang__Void Array___load__()
{
}


structs__Array *Array_new(lang__Class *T, lang__SizeT size)
{
	structs__Array *this = ((structs__Array *) Class_alloc(Array_class()));
	this->T = T;
	Array_init(this, size);
	return this;
}


structs__Array *Array_new_withData(lang__Class *T, lang__Pointer data, lang__SizeT size)
{
	structs__Array *this = ((structs__Array *) Class_alloc(Array_class()));
	this->T = T;
	Array_init_withData(this, data, size);
	return this;
}



lang__Void ArrayIterator___defaults___impl(structs__ArrayIterator *this)
{
	Iterator___defaults___impl((lang__Iterator *) this);
	this->i = 0;
}

lang__Void ArrayIterator___destroy___impl(structs__ArrayIterator *this)
{
}

lang__Void ArrayIterator_init_impl(structs__ArrayIterator *this, structs__Array *array)
{
	this->array = array;
}

lang__Bool ArrayIterator_hasNext_impl(structs__ArrayIterator *this)
{
	return this->i < this->array->size;
}

void ArrayIterator_next_impl(structs__ArrayIterator *this, lang__Pointer returnarg230)
{
	uint8_t value[this->T->size];
	Array_get(this->array, value, this->i);
	this->i += 1;
	if (returnarg230)
	{
		memcpy(returnarg230, ((lang__Pointer) (value)), this->T->size);
	}
	return;
}

lang__Class *ArrayIterator_class()
{
	static lang__Bool __done__ = false;
	static structs__ArrayIteratorClass class = 
	{
		{
			{
				{
					.instanceSize = sizeof(structs__ArrayIterator),
					.size = sizeof(void*),
					.name = "ArrayIterator",
				},
				.__load__ = (lang__Void (*)()) ArrayIterator___load__,
				.__defaults__ = (lang__Void (*)(lang__Object *)) ArrayIterator___defaults___impl,
				.__destroy__ = (lang__Void (*)(lang__Object *)) ArrayIterator___destroy___impl,
			},
			.hasNext = (lang__Bool (*)(lang__Iterator *)) ArrayIterator_hasNext_impl,
			.next = (lang__Void (*)(lang__Iterator *, lang__Pointer)) ArrayIterator_next_impl,
		},
		.new = ArrayIterator_new,
		.init = ArrayIterator_init_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Iterator_class();
	}
	return classPtr;
}


lang__Void ArrayIterator___defaults__(structs__ArrayIterator *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void ArrayIterator___destroy__(structs__ArrayIterator *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void ArrayIterator_init(structs__ArrayIterator *this, structs__Array *array)
{
	((structs__ArrayIteratorClass *)((lang__Object *)this)->class)->init((structs__ArrayIterator *) this, array);
}


lang__Bool ArrayIterator_hasNext(structs__ArrayIterator *this)
{
	return (lang__Bool)((lang__IteratorClass *)((lang__Object *)this)->class)->hasNext((lang__Iterator *) this);
}


void ArrayIterator_next(structs__ArrayIterator *this, lang__Pointer returnarg230)
{
	((lang__IteratorClass *)((lang__Object *)this)->class)->next((lang__Iterator *) this, returnarg230);
}


lang__Void ArrayIterator___load__()
{
}


structs__ArrayIterator *ArrayIterator_new(lang__Class *T, structs__Array *array)
{
	structs__ArrayIterator *this = ((structs__ArrayIterator *) Class_alloc(ArrayIterator_class()));
	this->T = T;
	ArrayIterator_init(this, array);
	return this;
}


void __OP_IDX_Array_Int__T(lang__Pointer returnarg231, lang__Class *T, structs__Array *arr, lang__Int index)
{
	
	{
		uint8_t gcall316[T->size];
		Array_get(arr, gcall316, index);
		if (returnarg231)
		{
			memcpy(returnarg231, ((lang__Pointer) (gcall316)), T->size);
		}
		return;
	};
}

lang__Void __OP_IDX_ASS_Array_Int_T(lang__Class *T, structs__Array *arr, lang__Int index, uint8_t * value)
{
	Array_set(arr, index, value);
}


lang__Void _structs_Array_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		Array___load__();
		ArrayIterator___load__();
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
		_lang_String_load();
	}
}

