/* EagleAI source file, generated with ooc */
#include "EagleAI.h"

lang__Void EagleAI___defaults___impl(EagleAI *this)
{
	AI___defaults___impl((AI *) this);
}

lang__Void EagleAI___destroy___impl(EagleAI *this)
{
}

lang__Void EagleAI_init_impl(EagleAI *this)
{
}

lang__Double EagleAI_dist_impl(EagleAI *this, GameInfo *info, lang__Int a, lang__Int b)
{
	if (true)
	{
		return Vector2_length((__OP_SUB_Vector2_Vector2__Vector2((*info).chars[a], (*info).chars[b])));
	}
}

lang__Void EagleAI_checkID_impl(EagleAI *this)
{
}

lang__Void EagleAI_stepImpl_impl(EagleAI *this, GameInfo *info)
{
	if ((*info).numChars == 1 && rand() % 40 == 10)
	{
		lang__Int x = rand() % 100;
		AI_mouse((AI *) this, cos(((lang__Double) (x))) * 100, sin(((lang__Double) (x))) * 100);
	}
	else if ((*info).numChars != 1)
	{
		Vector2 target = __OP_SUB_Vector2_Vector2__Vector2((*info).chars[0], (*info).chars[1]);
		lang__Double dst = EagleAI_dist(this, info, 0, 1);
		dbg_msg("EagleAI", "target_dist: %f", dst);
		AI_mouse((AI *) this, target.x, target.y);
		if (dst < 600)
		{
			AI_fire((AI *) this);
			if (dst < 300)
			{
				AI_hook_count((AI *) this, 15);
			}
		}
	}
	else 
	{
		dbg_msg("EagleAI", "!no target!");
	}
}

lang__Class *EagleAI_class()
{
	static lang__Bool __done__ = false;
	static EagleAIClass class = 
	{
		{
			{
				{
					.instanceSize = sizeof(EagleAI),
					.size = sizeof(void*),
					.name = "EagleAI",
				},
				.__load__ = (lang__Void (*)()) EagleAI___load__,
				.__defaults__ = (lang__Void (*)(lang__Object *)) EagleAI___defaults___impl,
				.__destroy__ = (lang__Void (*)(lang__Object *)) EagleAI___destroy___impl,
			},
			.stepImpl = (lang__Void (*)(AI *, GameInfo *)) EagleAI_stepImpl_impl,
			.step = (Answer (*)(AI *, GameInfo)) AI_step_impl,
			.jump = (lang__Void (*)(AI *)) AI_jump_impl,
			.left = (lang__Void (*)(AI *)) AI_left_impl,
			.right = (lang__Void (*)(AI *)) AI_right_impl,
			.fire = (lang__Void (*)(AI *)) AI_fire_impl,
			.hook = (lang__Void (*)(AI *)) AI_hook_impl,
			.hook_count = (lang__Void (*)(AI *, lang__Int)) AI_hook_count_impl,
			.target = (lang__Void (*)(AI *, lang__Float, lang__Float)) AI_target_impl,
			.mouse = (lang__Void (*)(AI *, lang__Float, lang__Float)) AI_mouse_impl,
		},
		.new = EagleAI_new,
		.init = EagleAI_init_impl,
		.dist = EagleAI_dist_impl,
		.checkID = EagleAI_checkID_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = AI_class();
	}
	return classPtr;
}


lang__Void EagleAI___defaults__(EagleAI *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void EagleAI___destroy__(EagleAI *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void EagleAI_init(EagleAI *this)
{
	((EagleAIClass *)((lang__Object *)this)->class)->init((EagleAI *) this);
}


lang__Double EagleAI_dist(EagleAI *this, GameInfo *info, lang__Int a, lang__Int b)
{
	return (lang__Double)((EagleAIClass *)((lang__Object *)this)->class)->dist((EagleAI *) this, info, a, b);
}


lang__Void EagleAI_checkID(EagleAI *this)
{
	((EagleAIClass *)((lang__Object *)this)->class)->checkID((EagleAI *) this);
}


lang__Void EagleAI_stepImpl(EagleAI *this, GameInfo *info)
{
	((AIClass *)((lang__Object *)this)->class)->stepImpl((AI *) this, info);
}


lang__Void EagleAI___load__()
{
}


EagleAI *EagleAI_new()
{
	EagleAI *this = ((EagleAI *) Class_alloc(EagleAI_class()));
	EagleAI_init(this);
	return this;
}



lang__Void _EagleAI_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		EagleAI___load__();
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
		_AI_load();
	}
}

