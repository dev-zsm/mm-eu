// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_fireshield.h"

void ref_func_80A4CE28(ObjFireshield* this, PlayState* play) {
    s32 pad;
    s32 sp30 = OBJFIRESHIELD_GET_FLAGS(&this->actor);
    s32 pad2[2];
    s32 sp24;
    s32 sp20;

    if (this->unk_1A8 == 0) {
        if (OBJFIRESHIELD_GET_2000(&this->actor)) {
            sp24 = false;
            sp20 = false;
        } else {
            sp24 = Flags_GetTreasure(play, OBJFIRESHIELD_GET_1F00(&this->actor));
            sp20 = false;
        }
    } else {
        sp20 = Flags_GetSwitch(play, OBJFIRESHIELD_GET_SWITCH_FLAG(&this->actor));
        sp24 = false;
    }

    if (!sp24 || !sp20 || (this->unk_19C != 0)) {
        s32 sp1C = Flags_GetSwitch(play, sp30);
        s32 temp_v0 = (sp30 & ~0x1F) >> 5;

        if (this->unk_19C == 2) {
            if (Math_StepToF(&this->unk_198, 1.0f, 0.03f)) {
                this->unk_19C = 1;
                if (((this->actor.home.rot.z * 10) > 0) && (this->unk_1A7 != 0)) {
                    Flags_UnsetSwitch(play, sp30);
                    sp1C = false;
                }
            }
        } else if (this->unk_19C == 3) {
            if (Math_StepToF(&this->unk_198, 0.0f, 0.03f)) {
                this->unk_19C = 0;
            }
        }

        if ((this->unk_1A0 > 0) && (this->unk_19C == 1) && ((this->actor.home.rot.z * 10) > 0) &&
            !(ref_D_80A4D894[temp_v0] & (1 << (sp30 & 0x1F)))) {
            this->unk_1A0 = 0;
        }

        if ((this->unk_19C == 0) || (this->unk_19C == 3)) {
            if (!sp24 && !sp20) {
                if ((this->actor.home.rot.z * 10) > 0) {
                    if (this->unk_1A0 > 1) {
                        this->unk_1A0--;
                    }

                    if (this->unk_1A0 == 1) {
                        this->unk_19C = 2;
                    }
                }

                if (!sp1C) {
                    this->unk_19C = 2;
                }
            }
        } else if (sp24 || sp20) {
            this->unk_19C = 3;
        } else if (sp1C && ((this->unk_19C == 1) || (this->unk_19C == 2))) {
            if ((ref_D_80A4D884[temp_v0] & 1 << (sp30 & 0x1F)) && !(ref_D_80A4D874[temp_v0] & 1 << (sp30 & 0x1F))) {
                this->unk_19C = 3;
            } else if (((this->actor.home.rot.z * 10) == 0) || (this->unk_1A0 == 0)) {
                if ((this->actor.home.rot.z * 10) > 0) {
                    this->unk_1A0 = this->actor.home.rot.z * 10;
                }

                if (this->unk_1A7 != 0) {
                    ref_func_80A4CA90(this);
                }
            }
        }
    }
}
