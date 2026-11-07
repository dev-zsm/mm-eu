// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_toge.h"

void ref_func_809A48AC(ObjToge* this, PlayState* play) {
    s32 pad;
    s32 sp30 = this->unk_194 ^ 1;

    if (this->unk_1B4 && (this->unk_194 == 1)) {
        Math_StepToF(&this->actor.speed, 2.0f, 0.4f);
    } else {
        Math_StepToF(&this->actor.speed, ref_D_809A4CDC[OBJTOGE_GET_700(&this->actor)], 1.5f);
        this->actor.shape.rot.y += 0x1770;
    }

    Actor_MoveWithGravity(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 10.0f, ref_D_809A4D0C[OBJTOGE_GET_4000(&this->actor)] * 30.0f, 0.0f,
                            UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_80);

    if (this->actor.bgCheckFlags & BGCHECKFLAG_WALL) {
        this->actor.world.rot.y = Math_Vec3f_Yaw(&this->actor.world.pos, &this->unk_198[this->unk_194]);
        this->unk_194 = sp30;
        if (this->unk_1B4 && (this->unk_194 == 0)) {
            ref_func_809A4804(this);
        } else {
            ref_func_809A4744(this);
        }
        Actor_PlaySfx(&this->actor, NA_SE_EV_SPINE_TRAP_MOVE);
    } else {
        s16 yaw = Math_Vec3f_Yaw(&this->actor.world.pos, &this->unk_198[sp30]) - this->actor.world.rot.y;

        yaw = ABS_ALT(yaw);
        if ((yaw > 0x4000) || (yaw == -0x8000)) {
            this->actor.world.rot.y = Math_Vec3f_Yaw(&this->actor.world.pos, &this->unk_198[this->unk_194]);
            this->unk_194 = sp30;
            if (this->unk_1B4 && (this->unk_194 == 0)) {
                ref_func_809A4804(this);
            } else {
                ref_func_809A4744(this);
            }
            Actor_PlaySfx(&this->actor, NA_SE_EV_SPINE_TRAP_MOVE);
        }
    }
}
