// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void BgHakuginSwitch_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    BgHakuginSwitch* this = (BgHakuginSwitch*)thisx;
    f32 sp24;

    if (this->unk_1B2 > 0) {
        this->unk_1B2--;
    }

    if (this->unk_1BF > 0) {
        if ((this->actionFunc != ref_func_80B15A68) && (this->actionFunc != ref_func_80B161A0)) {
            this->unk_1BF--;
            if (this->unk_1BF == 0) {
                CutsceneManager_Stop(this->curCsId);
            }
        }
    }

    this->actionFunc(this, play);

    sp24 = this->dyna.actor.shape.yOffset * this->dyna.actor.scale.y;

    if (this->unk_1C0 != 0) {
        f32 phi_f0;

        if (DynaPolyActor_IsSwitchPressed(&this->dyna)) {
            if (DynaPolyActor_IsHeavySwitchPressed(&this->dyna)) {
                phi_f0 = (sp24 - -10.0f) * -0.21f;
            } else {
                phi_f0 = (sp24 - -3.0f) * -0.08f;
            }
            this->unk_1C4 += phi_f0;
            this->unk_1C4 *= 0.75f;
            this->dyna.actor.shape.yOffset += this->unk_1C4 * this->unk_1C8;
        } else {
            this->unk_1C4 += sp24 * -0.11f;
            this->unk_1C4 *= 0.75f;
            this->dyna.actor.shape.yOffset += this->unk_1C4 * this->unk_1C8;
            this->dyna.actor.shape.yOffset = CLAMP_MAX(this->dyna.actor.shape.yOffset, 0.0f);
        }
    } else {
        Math_StepToF(&this->dyna.actor.shape.yOffset, 0.0f, 2.0f * this->unk_1C8);
        this->unk_1C4 = 0.0f;
    }
}
