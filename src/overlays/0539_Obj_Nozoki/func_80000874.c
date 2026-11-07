// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

void ref_func_80BA2C94(ObjNozoki* this, PlayState* play) {
    s32 temp_v0 = ref_func_80BA2C28(this);
    f32 sp38;
    f32 sp34;
    f32 temp_f0;

    if (temp_v0 >= 0) {
        ref_D_80BA36B4 = temp_v0;
    }

    if ((temp_v0 < 0) && Play_InCsMode(play)) {
        return;
    }

    if (ref_D_80BA36B8 < ref_D_80BA34D8[ref_D_80BA36B4]) {
        sp38 = this->dyna.actor.home.pos.y - this->dyna.actor.world.pos.y;

        if ((this->unk_15D != 1) && Flags_GetSwitch(play, this->dyna.actor.world.rot.z)) {
            ref_func_80BA2B64(this, play, 1, this->dyna.actor.world.rot.x);
        } else if ((this->unk_15D != 2) && Flags_GetSwitch(play, this->dyna.actor.world.rot.x)) {
            ref_func_80BA2B64(this, play, 2, this->dyna.actor.world.rot.z);
        } else if (DECR(this->unk_15E) == 0) {
            this->unk_15D = 0;
            Flags_UnsetSwitch(play, this->dyna.actor.world.rot.z);
            Flags_UnsetSwitch(play, this->dyna.actor.world.rot.x);
        }

        Math_StepToF(&this->dyna.actor.speed, ref_D_80BA34E4[this->unk_15D], 0.1f);

        if ((play->actorCtx.flags & ACTORCTX_FLAG_6) || (play->actorCtx.flags & ACTORCTX_FLAG_5)) {
            temp_f0 = 0.5f;
        } else {
            temp_f0 = this->dyna.actor.speed;
        }

        sp34 = Math_Vec3f_StepToXZ(&this->dyna.actor.world.pos, &this->dyna.actor.home.pos, temp_f0);

        ref_D_80BA36B8 += this->dyna.actor.speed;

        if (play->actorCtx.flags & ACTORCTX_FLAG_6) {
            if (sp34 <= 5.0f) {
                Actor_Kill(&this->dyna.actor);
            }
        } else if (!(play->actorCtx.flags & ACTORCTX_FLAG_5) && (GET_PLAYER(play)->actor.id == ACTOR_PLAYER) &&
                   Flags_GetSwitch(play, OBJNOZOKI_GET_SWITCH_FLAG2(&this->dyna.actor)) && (sp38 < 20.0f)) {
            static Vec3f ref_D_80BA34F0 = { 0.0f, 0.0f, 50.0f };

            play->actorCtx.flags |= ACTORCTX_FLAG_6;
            Lib_Vec3f_TranslateAndRotateY(&this->dyna.actor.home.pos, this->dyna.actor.shape.rot.y, &ref_D_80BA34F0,
                                          &this->dyna.actor.world.pos);
            this->dyna.actor.shape.rot.x = -0x1F40;
        } else if (sp34 < 50.0f) {
            play->actorCtx.flags |= ACTORCTX_FLAG_5;

            if (sp34 < 20.0f) {
                this->dyna.actor.velocity.y -= 0.4f;
                this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;

                sp38 = this->dyna.actor.home.pos.y - this->dyna.actor.world.pos.y;
                if (sp38 >= 100.0f) {
                    Actor_Kill(&this->dyna.actor);
                }

                this->dyna.actor.shape.rot.x = -0x1F40 - TRUNCF_BINANG(sp38 * 400.0f);
            }
        }
    }

    this->dyna.actor.velocity.x += this->dyna.actor.speed * 0.66f;
    if (this->dyna.actor.velocity.x >= 0x10000) {
        this->dyna.actor.velocity.x -= 0x10000;
    }

    play->roomCtx.unk7A[0] = this->dyna.actor.velocity.x;

    Audio_PlaySfx_AtPosWithFreq(&gSfxDefaultPos, NA_SE_EV_SECOM_CONVEYOR - SFX_FLAG, this->dyna.actor.speed);
}
