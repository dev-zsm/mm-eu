// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_fireshield.h"

void ref_func_80A4CD34(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjFireshield* this = (ObjFireshield*)thisx;
    s32 isSwitchFlagSet = Flags_GetSwitch(play, OBJFIRESHIELD_GET_FLAGS(&this->actor));
    s32 phi_v1;
    s32 phi_a0;

    if (this->unk_1A8 == 0) {
        if (OBJFIRESHIELD_GET_2000(&this->actor)) {
            phi_v1 = false;
            phi_a0 = false;
        } else {
            phi_v1 = Flags_GetTreasure(play, OBJFIRESHIELD_GET_1F00(&this->actor));
            phi_a0 = false;
        }
    } else {
        phi_a0 = Flags_GetSwitch(play, OBJFIRESHIELD_GET_SWITCH_FLAG(&this->actor));
        phi_v1 = false;
    }

    if (phi_v1 || phi_a0) {
        this->unk_19C = 0;
    } else if (isSwitchFlagSet) {
        this->unk_19C = 0;
    } else {
        this->unk_19C = 1;
    }

    if (this->unk_19C == 0) {
        this->unk_198 = 0.0f;
    } else {
        this->unk_198 = 1.0f;
    }
}
