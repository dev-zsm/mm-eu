// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B82DE0(BgDblueBalance* this, PlayState* play) {
    s32 pad;
    f32 sp88 = Math_CosS(this->dyna.actor.shape.rot.z * 2.2499313f);
    Actor* actor = &this->dyna.actor;
    s32 pad2;
    s16 abs;
    s32 phi_a0;
    s32 phi_a1;
    f32 phi_f2;
    f32 temp2;
    Vec3f sp60;
    BgDblueBalance* sp5C;
    Vec3f sp50;
    s32 pad3;
    Vec3f sp40;
    BgDblueBalance* sp3C;
    Vec3f sp30;

    if (Flags_GetSwitch(play, BGDBLUEBALANCE_GET_SWITCH_FLAG(&this->dyna.actor))) {
        if (this->unk_17D > 0) {
            this->unk_17D--;
        } else {
            this->unk_174 = -0x1C72;
            this->unk_176 = (s32)(sp88 * -300.0f) - 60;
        }
    } else {
        BgDblueBalance* balance1 = this->unk_160;
        BgDblueBalance* balance2 = this->unk_15C;

        phi_a0 = 0;
        phi_a1 = 1;
        this->unk_17D = 20;
        if (balance1 != NULL) {
            if (balance1->isHeavySwitchPressed) {
                phi_a0 = 4;
            } else if (balance1->isSwitchPressed) {
                phi_a0 = 2;
            }
        }

        if (balance2 != NULL) {
            if (balance2->isHeavySwitchPressed) {
                phi_a1 = 5;
            } else if (balance2->isSwitchPressed) {
                phi_a1 = 3;
            }
        }

        if (phi_a0 < phi_a1) {
            this->unk_174 = 0x1C72;
            this->unk_176 = (s32)(sp88 * 370.0f) + 80;
        } else {
            this->unk_174 = -0x1C72;
            this->unk_176 = (s32)(sp88 * -160.0f) - 80;
        }
    }

    if (this->dyna.actor.shape.rot.z == this->unk_174) {
        this->unk_178 = 0;
        this->unk_17C = 0;
        return;
    }

    abs = this->dyna.actor.shape.rot.z - this->unk_174;
    abs = ABS_ALT(abs);

    if ((this->unk_17C > 0) && (abs < 0x7D0)) {
        phi_a0 = 3;
    } else {
        phi_a0 = 40;
        this->unk_17C = 0;
    }

    if (this->unk_176 >= 0) {
        this->unk_178 += phi_a0;
        if (this->unk_176 < this->unk_178) {
            this->unk_178 = this->unk_176;
        }
    } else {
        this->unk_178 -= phi_a0;
        if (this->unk_178 < this->unk_176) {
            this->unk_178 = this->unk_176;
        }
    }

    phi_f2 = this->unk_178;
    temp2 = this->unk_17A;
    if ((phi_f2 * temp2) <= 0.0f) {
        AudioSfx_StopByPosAndId(&this->dyna.actor.projectedPos, NA_SE_EV_SEESAW_INCLINE - SFX_FLAG);
    }

    phi_f2 *= 0.0022222223f;
    phi_f2 = fabsf(phi_f2);
    if (phi_f2 > 1.0f) {
        phi_f2 = 1.0f;
    }

    Audio_PlaySfx_AtPosWithFreq(&this->dyna.actor.projectedPos, NA_SE_EV_SEESAW_INCLINE - SFX_FLAG, phi_f2 + 1.0f);
    actor->shape.rot.z += this->unk_178;

    if (this->dyna.actor.shape.rot.z > 0x1C71) {
        if (this->unk_17C < 2) {
            actor->shape.rot.z = 0x1C71;
            this->unk_178 *= -0.6f;
            this->unk_17C++;
            if (this->unk_182) {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_SEESAW_WATER_BOUND);
                sp5C = this->unk_15C;
                Matrix_Push();
                Matrix_RotateYS(BINANG_SUB(this->dyna.actor.shape.rot.y, 0x4000), MTXMODE_NEW);
                Matrix_MultVecZ(45.0f, &sp60);
                Matrix_Pop();

                sp50.x = sp5C->dyna.actor.world.pos.x + sp60.x;
                sp50.y = this->unk_228;
                sp50.z = sp5C->dyna.actor.world.pos.z + sp60.z;

                ref_func_80B8296C(play, &sp50, 70.0f);
            } else {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_SEESAW_BOUND);
            }
        } else {
            this->dyna.actor.shape.rot.z = 0x1C72;
            this->unk_178 = 0;
        }
    } else if (this->dyna.actor.shape.rot.z < -0x1C71) {
        if (this->unk_17C < 2) {
            actor->shape.rot.z = -0x1C71;
            this->unk_178 *= -0.6f;
            this->unk_17C++;
            if (this->unk_182) {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_SEESAW_WATER_BOUND);
                sp3C = this->unk_160;
                Matrix_Push();
                Matrix_RotateYS(BINANG_ADD(this->dyna.actor.shape.rot.y, 0x4000), MTXMODE_NEW);
                Matrix_MultVecZ(30.0f, &sp40);
                Matrix_Pop();

                sp30.x = sp3C->dyna.actor.world.pos.x + sp40.x;
                sp30.y = this->unk_228;
                sp30.z = sp3C->dyna.actor.world.pos.z + sp40.z;

                ref_func_80B8296C(play, &sp30, 47.0f);
            } else {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_SEESAW_BOUND);
            }
        } else {
            this->dyna.actor.shape.rot.z = -0x1C72;
            this->unk_178 = 0;
        }
    }
    ref_func_80B823B0(this);
}
