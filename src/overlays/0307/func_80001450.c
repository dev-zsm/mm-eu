// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void ref_func_80A2AED0(BgDblueMovebg* this, PlayState* play) {
    s32 pad;
    s32 temp_v0_3;

    if (play->roomCtx.curRoom.num != this->unk_170) {
        if (play->roomCtx.curRoom.num != this->unk_171) {
            if ((play->roomCtx.prevRoom.num != this->unk_170) && (play->roomCtx.prevRoom.num != this->unk_171)) {
                ref_D_80A2BBF4.unk_00 = 0;
                Actor_Kill(&this->dyna.actor);
                return;
            }
        }
    }

    temp_v0_3 = ref_func_80A29A80(play, this->switchFlag, this->unk_1BC);
    if (temp_v0_3 != this->unk_178) {
        switch (temp_v0_3) {
            case 1:
            case 2:
                this->csId = this->csIdList[0];
                this->unk_17E = 40;
                break;

            case 0:
            case 3:
                this->csId = this->csIdList[1];
                this->unk_17E = 15;
                break;
        }
        this->unk_172 |= 8;
    }
    this->unk_178 = temp_v0_3;

    if (!(this->unk_172 & 8)) {
        if (this->unk_17E <= 0) {
            this->unk_1CE = ref_D_80A2B96C[temp_v0_3];
        } else {
            this->unk_17E--;
        }
    }

    Math_StepToS(&this->unk_1CC, this->unk_1CE, 12);
    this->dyna.actor.shape.rot.x += this->unk_1CC;

    if (this->unk_160 == 8) {
        if (play->roomCtx.curRoom.num == 8) {
            ref_func_80A2ABD0(this, play);
            this->unk_172 |= 0x20;
        } else {
            this->unk_172 &= ~0x20;
        }
    }

    if (play->roomCtx.curRoom.num == 0) {
        this->opaDList = gGreatBayTempleObjectWaterwheelDL;
    } else if (play->roomCtx.curRoom.num == 8) {
        this->opaDList = gGreatBayTempleObjectWaterwheelWithFakeGearDL;
    }

    if (this == ref_D_80A2BBF0) {
        Vec3f sp54;
        f32 sp50;

        if (Math3D_PointDistSqToLine2DImpl(play->view.eye.x, play->view.eye.z, this->unk_190.x, this->unk_190.z,
                                           this->unk_19C.x, this->unk_19C.z, &sp54.x, &sp54.z, &sp50)) {
            sp54.y = this->dyna.actor.world.pos.y;
        } else {
            if (Math_Vec3f_DistXYZ(&play->view.eye, &this->unk_190) <=
                Math_Vec3f_DistXYZ(&play->view.eye, &this->unk_19C)) {
                Math_Vec3f_Copy(&sp54, &this->unk_190);
            } else {
                Math_Vec3f_Copy(&sp54, &this->unk_19C);
            }
        }

        SkinMatrix_Vec3fMtxFMultXYZ(&play->viewProjectionMtxF, &sp54, &this->unk_1A8);
        this->unk_1D4 = ABS(this->unk_1CC) / 364.0f;
    }
}
