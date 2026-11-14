// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_InitShop), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_trt.h"

void func_800035CC(EnTrt* this, PlayState* play) {
    EnTrt_GetCutscenes(this, play);
    this->csId = this->lookForwardCutscene;
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
    EnTrt_InitShopkeeper(this, play);
    this->actor.colChkInfo.mass = MASS_IMMOVABLE;
    this->actor.colChkInfo.cylRadius = 50;
    this->timer = Rand_S16Offset(40, 20);
    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_SAVED_KOUME) &&
        !CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_RED_POTION_FOR_KOUME) && gSaveContext.save.day >= 2) {
        this->textId = 0x84A;
        this->actionFunc = EnTrt_ShopkeeperGone;
    } else {
        this->sleepSoundTimer = 10;
        this->actor.textId = 0;
        this->actionFunc = EnTrt_IdleSleeping;
    }

    this->cursorPos.y = this->cursorPos.x = 100.0f;
    this->stickAccumY = 0;
    this->stickAccumX = 0;

    this->cursorIndex = 0;
    this->cursorPos.z = 1.2f;
    this->cursorColor.r = 0;
    this->cursorColor.g = 80;
    this->cursorColor.b = 255;
    this->cursorColor.a = 255;
    this->cursorAnimTween = 0.0f;
    this->cursorAnimState = 0;
    this->drawCursor = 0;

    this->stickLeftPrompt.stickColor.r = 200;
    this->stickLeftPrompt.stickColor.g = 200;
    this->stickLeftPrompt.stickColor.b = 200;
    this->stickLeftPrompt.stickColor.a = 180;
    this->stickLeftPrompt.stickTexX = 49.0f;
    this->stickLeftPrompt.stickTexY = 95.0f;
    this->stickLeftPrompt.arrowColor.r = 255;
    this->stickLeftPrompt.arrowColor.g = 255;
    this->stickLeftPrompt.arrowColor.b = 0;
    this->stickLeftPrompt.arrowColor.a = 200;
    this->stickLeftPrompt.arrowTexX = 33.0f;
    this->stickLeftPrompt.arrowTexY = 91.0f;
    this->stickLeftPrompt.texZ = 1.0f;
    this->stickLeftPrompt.isEnabled = false;

    this->stickRightPrompt.stickColor.r = 200;
    this->stickRightPrompt.stickColor.g = 200;
    this->stickRightPrompt.stickColor.b = 200;
    this->stickRightPrompt.stickColor.a = 180;
    this->stickRightPrompt.stickTexX = 274.0f;
    this->stickRightPrompt.stickTexY = 95.0f;
    this->stickRightPrompt.arrowColor.r = 255;
    this->stickRightPrompt.arrowColor.g = 0;
    this->stickRightPrompt.arrowColor.b = 0;
    this->stickRightPrompt.arrowColor.a = 200;
    this->stickRightPrompt.arrowTexX = 290.0f;
    this->stickRightPrompt.arrowTexY = 91.0f;
    this->stickRightPrompt.texZ = 1.0f;
    this->stickRightPrompt.isEnabled = false;

    this->arrowAnimTween = 0.0f;
    this->stickAnimTween = 0.0f;
    this->arrowAnimState = 0;
    this->stickAnimState = 0;
    this->shopItemSelectedTween = 0.0f;

    this->actor.gravity = 0.0f;
    Actor_SetScale(&this->actor, sActorScale);
    EnTrt_SpawnShopItems(this, play, sShop);
    this->blinkTimer = 20;
    this->eyeTexIndex = 0;
    this->blinkFunc = EnTrt_EyesClosed;
    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_GAVE_KOTAKE_MUSHROOM)) {
        this->flags |= ENTRT_GIVEN_MUSHROOM;
    }

    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
}
