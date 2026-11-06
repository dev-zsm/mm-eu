// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B833C4(BgDblueBalance* this, PlayState* play) {
    Actor* thisx = &this->dyna.actor;
#if MM_VERSION >= N64_US
    s32 sp28 = false;
    s16 sp26;
    s16 sp24;

    if (this->isSwitchFlagSet) {
        if (!this->isSwitchFlagSet2 && (this->unk_17F == 0)) {
            this->unk_17F = 1;
        }

        if (this->unk_186 != 0) {
            if (this->unk_178 >= 0x50) {
                this->unk_178 -= 5;
            }
        }
    } else {
        this->unk_187 = Math_StepToS(&this->unk_178, 0x1F4, 5);
    }

    sp26 = thisx->shape.rot.x;
    thisx->shape.rot.x += this->unk_178;
    sp24 = thisx->shape.rot.x;

    if (this->isSwitchFlagSet) {
        if (this->unk_186 != 0) {
            if (ref_func_80B82B00(sp26, sp24, this->unk_184)) {
                sp28 = true;
            }
        } else if (this->unk_187 != 0) {
            if (ref_func_80B82B00(sp26, sp24, 0x2097)) {
                this->unk_184 = -0x8000;
                this->unk_186 = 1;
            } else if (ref_func_80B82B00(sp26, sp24, -0x5F69)) {
                this->unk_184 = 0;
                this->unk_186 = 1;
            }
        }
    }

    ref_func_80B8264C(this);

    if (sp28) {
        thisx->shape.rot.x = this->unk_184;
        ref_func_80B83344(this);
    }
#else
    if (this->isSwitchFlagSet) {
        if (!this->isSwitchFlagSet2 && (this->unk_17F == 0)) {
            this->unk_17F = 1;
        }

        if (this->unk_178 >= 0x50) {
            this->unk_178 -= 5;
            this->unk_17E_jp = 0;
        } else if (this->unk_17E_jp < 10) {
            this->unk_178 -= 10;
            this->unk_17E_jp++;
        } else {
            ref_func_80B83344(this);
        }
    } else {
        Math_StepToS(&this->unk_178, 0x1F4, 4);
    }

    thisx->shape.rot.x += this->unk_178;
    ref_func_80B8264C(this);
#endif
}
