/* structs.Array header file, generated with ooc */
#ifndef ___structs_Array__
#define ___structs_Array__


struct _structs__Array;
typedef struct _structs__Array structs__Array;
struct _structs__ArrayClass;
typedef struct _structs__ArrayClass structs__ArrayClass;
struct _structs__ArrayIterator;
typedef struct _structs__ArrayIterator structs__ArrayIterator;
struct _structs__ArrayIteratorClass;
typedef struct _structs__ArrayIteratorClass structs__ArrayIteratorClass;

#include <sdk/lang/Iterator.h>
#include <sdk/lang/String.h>
#include <sdk/lang/Float.h>
#include <sdk/lang/Interface.h>
#include <sdk/lang/Range.h>
#include <sdk/lang/Object.h>
#include <sdk/lang/TypeInfo.h>
#include <sdk/lang/Double.h>
#include <sdk/lang/Exception.h>
#include <sdk/lang/Char.h>
#include <sdk/lang/ooclib.h>
#include <sdk/lang/Bool.h>
#include <sdk/lang/stdio.h>
#include <sdk/lang/Iterable.h>
#include <sdk/lang/Int.h>
#include <sdk/lang/LLong.h>
#include <sdk/lang/String.h>

struct _structs__Array
{
	struct _lang__Iterable __super__;
	lang__Class *T;
	lang__SizeT size;
	uint8_t *data;
};


struct _structs__ArrayClass
{
	struct _lang__IterableClass __super__;
	structs__Array * (*new)(lang__Class *, lang__SizeT);
	lang__Void (*init)(structs__Array *, lang__SizeT);
	structs__Array * (*new_withData)(lang__Class *, lang__Pointer, lang__SizeT);
	lang__Void (*init_withData)(structs__Array *, lang__Pointer, lang__SizeT);
	lang__Void (*get)(structs__Array *, lang__Pointer, lang__Int);
	lang__Void (*set)(structs__Array *, lang__Int, uint8_t *);
	lang__Int (*size)(structs__Array *);
	lang__SizeT (*lastIndex)(structs__Array *);
	lang__Bool (*isEmpty)(structs__Array *);
	lang__Void (*each)(structs__Array *, void (*)(uint8_t *));
};


lang__Class *Array_class();

lang__Void Array___load__();
lang__Void Array___defaults__(structs__Array *this);
lang__Void Array___defaults___impl(structs__Array *this);
lang__Void Array___destroy__(structs__Array *this);
lang__Void Array___destroy___impl(structs__Array *this);
structs__Array *Array_new(lang__Class *T, lang__SizeT size);
lang__Void Array_init(structs__Array *this, lang__SizeT size);
lang__Void Array_init_impl(structs__Array *this, lang__SizeT size);
structs__Array *Array_new_withData(lang__Class *T, lang__Pointer data, lang__SizeT size);
lang__Void Array_init_withData(structs__Array *this, lang__Pointer data, lang__SizeT size);
lang__Void Array_init_withData_impl(structs__Array *this, lang__Pointer data, lang__SizeT size);
void Array_get(structs__Array *this, lang__Pointer returnarg214, lang__Int i);
void Array_get_impl(structs__Array *this, lang__Pointer returnarg214, lang__Int i);
lang__Void Array_set(structs__Array *this, lang__Int i, uint8_t * value);
lang__Void Array_set_impl(structs__Array *this, lang__Int i, uint8_t * value);
lang__Int Array_size(structs__Array *this);
lang__Int Array_size_impl(structs__Array *this);
lang__Iterator *Array_iterator(structs__Array *this);
lang__Iterator *Array_iterator_impl(structs__Array *this);
lang__SizeT Array_lastIndex(structs__Array *this);
lang__SizeT Array_lastIndex_impl(structs__Array *this);
lang__Bool Array_isEmpty(structs__Array *this);
lang__Bool Array_isEmpty_impl(structs__Array *this);
lang__Void Array_each(structs__Array *this, void (*f)(uint8_t *));
lang__Void Array_each_impl(structs__Array *this, void (*f)(uint8_t *));

struct _structs__ArrayIterator
{
	struct _lang__Iterator __super__;
	lang__Class *T;
	structs__Array *array;
	lang__Int i;
};


struct _structs__ArrayIteratorClass
{
	struct _lang__IteratorClass __super__;
	structs__ArrayIterator * (*new)(lang__Class *, structs__Array *);
	lang__Void (*init)(structs__ArrayIterator *, structs__Array *);
};


lang__Class *ArrayIterator_class();

lang__Void ArrayIterator___load__();
lang__Void ArrayIterator___defaults__(structs__ArrayIterator *this);
lang__Void ArrayIterator___defaults___impl(structs__ArrayIterator *this);
lang__Void ArrayIterator___destroy__(structs__ArrayIterator *this);
lang__Void ArrayIterator___destroy___impl(structs__ArrayIterator *this);
structs__ArrayIterator *ArrayIterator_new(lang__Class *T, structs__Array *array);
lang__Void ArrayIterator_init(structs__ArrayIterator *this, structs__Array *array);
lang__Void ArrayIterator_init_impl(structs__ArrayIterator *this, structs__Array *array);
lang__Bool ArrayIterator_hasNext(structs__ArrayIterator *this);
lang__Bool ArrayIterator_hasNext_impl(structs__ArrayIterator *this);
void ArrayIterator_next(structs__ArrayIterator *this, lang__Pointer returnarg230);
void ArrayIterator_next_impl(structs__ArrayIterator *this, lang__Pointer returnarg230);

void __OP_IDX_Array_Int__T(lang__Pointer returnarg231, lang__Class *T, structs__Array *arr, lang__Int index);
lang__Void __OP_IDX_ASS_Array_Int_T(lang__Class *T, structs__Array *arr, lang__Int index, uint8_t * value);
lang__Void _structs_Array_load();

#endif // ___structs_Array__

