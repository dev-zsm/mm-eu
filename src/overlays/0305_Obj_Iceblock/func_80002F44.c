// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A25FD4(ObjIceblock* this, PlayState* play) {
    s32 pad;
    s32 sp30;
    s32 sp2C;

    ref_func_80A23690(this);
    ref_func_80A23F90(this, play);
    sp2C = ref_func_80A25238(this);
    ref_func_80A252DC(this, sp2C);
    sp30 = true;

    if (sp2C == -1) {
        sp30 = false;
    } else {
        Vec3f sp20;

        if (!(this->unk_1B0 & 2) && (this->unk_26E[sp2C] >= 11) && !ref_func_80A24118(this, play, 2.0f, &sp20) &&
            !Player_InCsMode(play)) {
            ref_func_80A23370(this, sp2C);
            ref_func_80A260E8(this);
            sp30 = false;
            Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_WAIT);
            this->unk_1B0 |= 1;
        }
    }

    if (sp30) {
        ref_func_80A2541C(this, play);
    }
    ref_func_80A24A48(this, play);
}
