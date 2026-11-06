// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ref_func_80A22334(ObjSkateblock* this, PlayState* play) {
    s32 pad;
    s32 sp30;
    s32 sp2C;
    Vec3f sp20;

    ref_func_80A21CD8(this);
    ref_func_80A21548(this, play);
    sp2C = ref_func_80A21150(this);
    ref_func_80A211F4(this, sp2C);

    sp30 = true;

    if (sp2C == -1) {
        sp30 = false;
    } else if (!(this->unk_1C1 & 2) && (this->unk_172[sp2C] > 10) && (ref_D_80A22A10 == 0) &&
               !ref_func_80A216D4(this, play, 2.0f, &sp20) && !Player_InCsMode(play)) {
        ref_func_80A21C88(this, sp2C);
        ref_func_80A2244C(this);
        sp30 = false;
        Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_WAIT);
        this->unk_1C1 |= 1;
    }

    if (sp30) {
        ref_func_80A21CB4(this, play);
    }
}
