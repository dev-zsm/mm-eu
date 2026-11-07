// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA28DC(ObjNozoki* this, PlayState* play) {
    if (this->unk_15E != 0) {
        if (DECR(this->unk_15E) == 0) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_SLIDE_DOOR_OPEN);
        }
        return;
    }

    if (!(play->actorCtx.flags & ACTORCTX_FLAG_5)) {
        Math_StepToF(&this->dyna.actor.velocity.y, 15.0f, 3.0f);
        Math_StepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y + 200.0f, this->dyna.actor.velocity.y);

        if (OBJNOZOKI_GET_200(&this->dyna.actor)) {
            if (!Flags_GetSwitch(play, OBJNOZOKI_GET_SWITCH_FLAG1(&this->dyna.actor))) {
                return;
            }
        } else if (Flags_GetSwitch(play, OBJNOZOKI_GET_SWITCH_FLAG1(&this->dyna.actor))) {
            s32 csId = this->dyna.actor.csId;

            if (csId == this->csId) {
                if (OBJNOZOKI_GET_400(&this->dyna.actor)) {
                    Vec3f sp28;

                    Actor_WorldToActorCoords(&this->dyna.actor, &sp28, &GET_PLAYER(play)->actor.world.pos);
                    if (sp28.z < -20.0f) {
                        this->csId = CutsceneManager_GetAdditionalCsId(this->csId);
                    }
                }
            } else if (ref_D_80BA36B4 == 0) {
                if (ref_func_80BA26A8(this)) {
                    ref_D_80BA36B4 = 1;
                }
            } else if (CutsceneManager_GetCurrentCsId() != this->csId) {
                this->csId = csId;
                this->dyna.actor.params &= ~OBJNOZOKI_400;
                SEQCMD_PLAY_SEQUENCE(SEQ_PLAYER_BGM_MAIN, 0, NA_BGM_ENEMY | 0x800 | SEQ_FLAG_ASYNC);
            }
            return;
        }
    }

    ObjNozoki_SetupAction(this, ref_func_80BA2AB4);
    this->dyna.actor.velocity.y = 0.0f;
    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_SLIDE_DOOR_CLOSE);
}
