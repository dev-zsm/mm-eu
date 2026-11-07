// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

void ObjComb_Update(Actor* thisx, PlayState* play) {
    ObjComb* this = (ObjComb*)thisx;

    this->unk_1B3 = (this->collider.base.acFlags & AC_HIT) != 0;
    if (this->unk_1B3) {
        this->collider.base.acFlags &= ~AC_HIT;
    }

    if (this->unk_1B2 > 0) {
        this->unk_1B2--;
        if (this->unk_1B2 == 0) {
            ref_func_8098DE58(this);
        }
    }

    this->actionFunc(this, play);

    if (this->actor.update == NULL) {
        if ((this->unk_1B5 == 2) && (CutsceneManager_GetCutsceneScriptIndex(this->actor.csId) == -1)) {
            CutsceneManager_Stop(this->actor.csId);
            this->unk_1B5 = 0;
        }
    } else {
        if (this->unk_1B5 != 0) {
            Actor_SetFocus(&this->actor, 0.0f);
            if (this->unk_1B5 == 1) {
                if (CutsceneManager_IsNext(this->actor.csId)) {
                    CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
                    if (this->actor.csId > CS_ID_NONE) {
                        Player_SetCsActionWithHaltedActors(play, &this->actor, PLAYER_CSACTION_1);
                    }

                    if (((OBJCOMB_GET_8000(&this->actor) | OBJCOMB_GET_80(&this->actor)) == 1) &&
                        OBJCOMB_GET_10(&this->actor)) {
                        SET_WEEKEVENTREG(WEEKEVENTREG_83_02);
                    }

                    this->unk_1B5 = 2;
                } else {
                    CutsceneManager_Queue(this->actor.csId);
                }
            }
        }

        if (this->unk_1B7 != 0) {
            play->actorCtx.flags |= ACTORCTX_FLAG_3;
            this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        }
    }
}
