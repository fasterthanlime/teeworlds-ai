/* NddAI source file, generated with ooc */
#include "NddAI.h"

lang__Void NddAI___defaults___impl(NddAI *this)
{
	AI___defaults___impl((AI *) this);
	this->bumpCount = 0;
	this->left = true;
	this->nextJump = 0;
	this->lastx = 0.0;
	this->lasty = 0.0;
}

lang__Void NddAI___destroy___impl(NddAI *this)
{
}

lang__Void NddAI_init_impl(NddAI *this)
{
}

lang__Void NddAI_stepImpl_impl(NddAI *this, GameInfo *info)
{
	dbg_msg("ia", "t %.2f pos (%.0f, %.0f) last (%.0f, %.0f), bumpCount %d, nextJump %d, hookCount %d", (*info).time, (*info).pos.x, (*info).pos.y, this->lastx, this->lasty, this->bumpCount, this->nextJump, ((AI*) this)->hookCount);
	lang__Bool tryJump = false;
	AI_mouse((AI *) this, 0 - 20, 0 - 60);
	
	{
		lang__Int i;
		for (i = 0; i < (*info).numChars; i++)
		{
			Vector2 pos = (*info).chars[i];
			dbg_msg("ai", "[ooc] client %d: %f,%f", i, pos.x, pos.y);
			if (i == 1)
			{
				dbg_msg("ia", "Following other player!!");
				this->left = (pos.x < (*info).pos.x);
				tryJump = (pos.y < (*info).pos.y);
			}
			if (i != 0 && (Double_abs((lang__Double) (pos.x - (*info).pos.x)) < 200) && (Double_abs((lang__Double) (pos.y - (*info).pos.y)) < 200))
			{
				Vector2 vec = __OP_SUB_Vector2_Vector2__Vector2(pos, (*info).pos);
				AI_mouse((AI *) this, vec.x, vec.y);
				dbg_msg("ia", "Firing at (%.0f, %.0f)!!", vec.x, vec.y);
				AI_fire((AI *) this);
			}
		}
	};
	if (Double_abs((lang__Double) (this->lastx - (*info).pos.x)) < 3.0)
	{
		this->bumpCount += 1;
	}
	else 
	{
		this->bumpCount = 0;
	}
	if (this->bumpCount == ((NddAIClass*) NddAI_class())->JUMP_THRESHOLD)
	{
		AI_jump((AI *) this);
	}
	else if (tryJump && this->nextJump <= 0)
	{
		srand(((lang__Int) ((*info).time)));
		this->nextJump = rand() % 50 + 20;
		AI_jump((AI *) this);
		AI_hook_count((AI *) this, 15);
	}
	if (this->nextJump >= 0)
	{
		this->nextJump -= 1;
	}
	if (this->bumpCount >= ((NddAIClass*) NddAI_class())->MAX_BUMP)
	{
		this->bumpCount = 0;
		this->left = !this->left;
	}
	if (this->left)
	{
		AI_left((AI *) this);
	}
	else 
	{
		AI_right((AI *) this);
	}
	this->lastx = (*info).pos.x;
	this->lasty = (*info).pos.y;
}

lang__Class *NddAI_class()
{
	static lang__Bool __done__ = false;
	static NddAIClass class = 
	{
		{
			{
				{
					.instanceSize = sizeof(NddAI),
					.size = sizeof(void*),
					.name = "NddAI",
				},
				.__load__ = (lang__Void (*)()) NddAI___load__,
				.__defaults__ = (lang__Void (*)(lang__Object *)) NddAI___defaults___impl,
				.__destroy__ = (lang__Void (*)(lang__Object *)) NddAI___destroy___impl,
			},
			.stepImpl = (lang__Void (*)(AI *, GameInfo *)) NddAI_stepImpl_impl,
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
		.new = NddAI_new,
		.init = NddAI_init_impl,
	};
	lang__Class *classPtr = (lang__Class *) &class;
	if(!__done__)
	{
		__done__ = true;
		classPtr->super = AI_class();
	}
	return classPtr;
}


lang__Void NddAI___defaults__(NddAI *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__defaults__((lang__Object *) this);
}


lang__Void NddAI___destroy__(NddAI *this)
{
	((lang__ObjectClass *)((lang__Object *)this)->class)->__destroy__((lang__Object *) this);
}


lang__Void NddAI_init(NddAI *this)
{
	((NddAIClass *)((lang__Object *)this)->class)->init((NddAI *) this);
}


lang__Void NddAI_stepImpl(NddAI *this, GameInfo *info)
{
	((AIClass *)((lang__Object *)this)->class)->stepImpl((AI *) this, info);
}


lang__Void NddAI___load__()
{
	((NddAIClass*) NddAI_class())->JUMP_THRESHOLD = 3;
	((NddAIClass*) NddAI_class())->MAX_BUMP = 20;
}


NddAI *NddAI_new()
{
	NddAI *this = ((NddAI *) Class_alloc(NddAI_class()));
	NddAI_init(this);
	return this;
}



lang__Void _NddAI_load()
{
	static lang__Bool __done__ = false;
	if (!__done__)
	{
		__done__ = true;
		NddAI___load__();
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

