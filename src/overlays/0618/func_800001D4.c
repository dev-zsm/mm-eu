// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombal.h"

void ref_func_80C05C44(EnBombal* this, PlayState* play) {
    s32 phi_s0 = false;
    s32 i;
    Vec3f effPos;

    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_75_40) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_73_10) &&
        !CHECK_WEEKEVENTREG(WEEKEVENTREG_85_02)) {
        if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
            CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            CutsceneManager_Queue(this->csId);
            return;
        }

        if (!CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_Queue(this->csId);
        } else {
            CutsceneManager_StartWithPlayerCs(this->csId, &this->actor);
            phi_s0 = true;
        }
    } else {
        phi_s0 = true;
    }

    if (phi_s0) {
        Math_Vec3f_Copy(&effPos, &this->actor.world.pos);
        effPos.y += 60.0f;
        Actor_Spawn(&play->actorCtx, play, ACTOR_EN_CLEAR_TAG, effPos.x, effPos.y, effPos.z, 255, 255, 200,
                    CLEAR_TAG_PARAMS(CLEAR_TAG_LARGE_EXPLOSION));

        for (i = 0; i < 100; i++) {
            EnBombal_InitEffects(this, &effPos, 10);
        }

        SET_WEEKEVENTREG(WEEKEVENTREG_83_04);
        Actor_PlaySfx(&this->actor, NA_SE_EV_MUJURA_BALLOON_BROKEN);
        this->timer = 30;
        this->isPopped = true;
        this->actionFunc = ref_func_80C05DE8;
    }
}
