/* AI source file, generated with ooc */
#include "AI.h"
lang__Class *Answer_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(Answer);
		_class->instanceSize = sizeof(Answer);
		_class->name = "Answer";
	}
	return _class;
}



lang__Void Actions___defaults___impl(Actions *this)
{
	Object___defaults___impl((lang__Object *) this);
}

lang__Void Actions___destroy___impl(Actions *this)
{
}

lang__Void Actions_init_impl(Actions *this)
{
}

lang__Class *Actions_class()
{
	static lang__Bool __done__ = false;
	static ActionsClass class = 
	{
		{
			{
				.instanceSize = sizeof(Actions),
				.size = sizeof(void*),
				.name = "Actions",
			},
			.__load__ = (lang__Void (*)()) Actions___load__,
			.__defaults__ = (lang__Void (*)(lang__Object *)) Actions___defaults___impl,
			.__destroy__ = (lang__Void (*)(lang__Object *)) Actions___destroy___impl,
		},
		.new = Actions_new,
		.init = Actions_init_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


lang__Void Actions___defaults__(Actions *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void Actions___destroy__(Actions *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void Actions_init(Actions *this)
{
	((ActionsClass *)((lang__Object *)this)->class)->init((Actions *) this);
}


lang__Void Actions___load__()
{
	((ActionsClass*) Actions_class())->NONE = 0;
	((ActionsClass*) Actions_class())->JUMP = 0x1;
	((ActionsClass*) Actions_class())->LEFT = 0x2;
	((ActionsClass*) Actions_class())->RIGHT = 0x4;
	((ActionsClass*) Actions_class())->FIRE = 0x8;
	((ActionsClass*) Actions_class())->HOOK = 0x10;
}


Actions *Actions_new()
{
	Actions *this = ((Actions *) Class_alloc(Actions_class()));
	Actions_init(this);
	return this;
}


lang__Class *Vector2_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(Vector2);
		_class->instanceSize = sizeof(Vector2);
		_class->name = "Vector2";
	}
	return _class;
}


lang__Double Vector2_length(Vector2 this)
{
	return sqrt(((lang__Double) this.x * this.x + this.y * this.y));
}


lang__Class *GameInfo_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(GameInfo);
		_class->instanceSize = sizeof(GameInfo);
		_class->name = "GameInfo";
	}
	return _class;
}


lang__Class *Action_class()
{
	static lang__Class *_class = NULL;
	if (_class == NULL)
	{
		_class = (lang__Pointer) GC_MALLOC(sizeof(lang__Class));
		_class->size = sizeof(Action);
		_class->instanceSize = sizeof(Action);
		_class->name = "Action";
	}
	return _class;
}


lang__Void Action_print(Action this)
{
	printf("[ ");
	if (this & ((ActionsClass*) Actions_class())->JUMP)
	{
		printf("jump ");
	}
	if (this & ((ActionsClass*) Actions_class())->LEFT)
	{
		printf("left ");
	}
	if (this & ((ActionsClass*) Actions_class())->RIGHT)
	{
		printf("right ");
	}
	if (this & ((ActionsClass*) Actions_class())->FIRE)
	{
		printf("fire ");
	}
	printf("]");
}



lang__Void AI___defaults___impl(AI *this)
{
	Object___defaults___impl((lang__Object *) this);
	this->hookCount = 0;
}

lang__Void AI___destroy___impl(AI *this)
{
}

Answer AI_step_impl(AI *this, GameInfo info)
{
	this->answer.action = 0;
	this->answer.target = NULL;
	this->answer.mouse = NULL;
	AI_stepImpl(this, &(info));
	if (this->hookCount > 0)
	{
		this->hookCount -= 1;
		AI_hook(this);
	}
	return this->answer;
}

lang__Void AI_jump_impl(AI *this)
{
	this->answer.action |= ((ActionsClass*) Actions_class())->JUMP;
}

lang__Void AI_left_impl(AI *this)
{
	this->answer.action |= ((ActionsClass*) Actions_class())->LEFT;
}

lang__Void AI_right_impl(AI *this)
{
	this->answer.action |= ((ActionsClass*) Actions_class())->RIGHT;
}

lang__Void AI_fire_impl(AI *this)
{
	this->answer.action |= ((ActionsClass*) Actions_class())->FIRE;
}

lang__Void AI_hook_impl(AI *this)
{
	this->answer.action |= ((ActionsClass*) Actions_class())->HOOK;
}

lang__Void AI_hook_count_impl(AI *this, lang__Int time)
{
	this->hookCount = time;
}

lang__Void AI_target_impl(AI *this, lang__Float x, lang__Float y)
{
	this->answer.target = (lang__Pointer) GC_MALLOC(Vector2_class()->size);
	((Vector2*) this->answer.target)->x = x;
	((Vector2*) this->answer.target)->y = y;
}

lang__Void AI_mouse_impl(AI *this, lang__Float x, lang__Float y)
{
	this->answer.mouse = (lang__Pointer) GC_MALLOC(Vector2_class()->size);
	((Vector2*) this->answer.mouse)->x = x;
	((Vector2*) this->answer.mouse)->y = y;
}

lang__Class *AI_class()
{
	static lang__Bool __done__ = false;
	static AIClass class = 
	{
		{
			{
				.instanceSize = sizeof(AI),
				.size = sizeof(void*),
				.name = "AI",
			},
			.__load__ = (lang__Void (*)()) AI___load__,
			.__defaults__ = (lang__Void (*)(lang__Object *)) AI___defaults___impl,
			.__destroy__ = (lang__Void (*)(lang__Object *)) AI___destroy___impl,
		},
		.stepImpl = AI_stepImpl,
		.step = AI_step_impl,
		.jump = AI_jump_impl,
		.left = AI_left_impl,
		.right = AI_right_impl,
		.fire = AI_fire_impl,
		.hook = AI_hook_impl,
		.hook_count = AI_hook_count_impl,
		.target = AI_target_impl,
		.mouse = AI_mouse_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = Object_class();
	}
	return classPtr;
}


lang__Void AI___defaults__(AI *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void AI___destroy__(AI *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void AI_stepImpl(AI *this, GameInfo *info)
{
	((AIClass *)((lang__Object *)this)->class)->stepImpl((AI *) this, info);
}


Answer AI_step(AI *this, GameInfo info)
{
	return (Answer)((AIClass *)((lang__Object *)this)->class)->step((AI *) this, info);
}


lang__Void AI_jump(AI *this)
{
	((AIClass *)((lang__Object *)this)->class)->jump((AI *) this);
}


lang__Void AI_left(AI *this)
{
	((AIClass *)((lang__Object *)this)->class)->left((AI *) this);
}


lang__Void AI_right(AI *this)
{
	((AIClass *)((lang__Object *)this)->class)->right((AI *) this);
}


lang__Void AI_fire(AI *this)
{
	((AIClass *)((lang__Object *)this)->class)->fire((AI *) this);
}


lang__Void AI_hook(AI *this)
{
	((AIClass *)((lang__Object *)this)->class)->hook((AI *) this);
}


lang__Void AI_hook_count(AI *this, lang__Int time)
{
	((AIClass *)((lang__Object *)this)->class)->hook_count((AI *) this, time);
}


lang__Void AI_target(AI *this, lang__Float x, lang__Float y)
{
	((AIClass *)((lang__Object *)this)->class)->target((AI *) this, x, y);
}


lang__Void AI_mouse(AI *this, lang__Float x, lang__Float y)
{
	((AIClass *)((lang__Object *)this)->class)->mouse((AI *) this, x, y);
}


lang__Void AI___load__()
{
}


Vector2 __OP_SUB_Vector2_Vector2__Vector2(Vector2 v1, Vector2 v2)
{
	Vector2 v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	return v;
}

Vector2 __OP_MUL_Vector2_Float__Vector2(Vector2 v, lang__Float f)
{
	Vector2 vout;
	vout.x = v.x * f;
	vout.y = v.y * f;
	return vout;
}


lang__Void _AI_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		Actions___load__();
		AI___load__();
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

