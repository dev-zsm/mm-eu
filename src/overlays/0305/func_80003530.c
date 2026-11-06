// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A265C0(ObjIceblock* this, PlayState* play) {
    s32 pad;
    ObjIceBlockUnkStruct4* ptr;

    if (ref_func_80A25238(this) != -1) {
        ref_func_80A2541C(this, play);
    }

    if (this->stateTimer > 0) {
        this->stateTimer--;
    } else {
        ptr = &this->unk_27C;
        this->stateTimer = Rand_S16Offset(30, 60);
        ptr->unk_0C = Rand_S16Offset(300, 300);
        ptr->unk_0E = Rand_S16Offset(900, 600);
        ptr->unk_04 = (2.0f * Rand_ZeroOne()) + 1.0f;
        ptr->unk_14 = Rand_Next() >> 0x10;
        ref_func_80A24B74(this, play);
    }

    ref_func_80A237A4(this);
    ref_func_80A23938(this);

    if (this->unk_1B0 & 0x40) {
        ref_func_80A24B74(this, play);
    }

    ref_func_80A24A48(this, play);
}
