// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chikuwa.h"

void ref_func_809B1AA0(ObjChikuwa* this) {
    ObjChikuwaStruct2* temp_v0;
    s32 i;

    this->unk_9A6 = 0;

    for (i = 0; i < ARRAY_COUNT(this->unk_2A4); i++) {
        temp_v0 = &this->unk_2A4[i];
        if (temp_v0->unk_34 > 0) {
            temp_v0->unk_34--;
            this->unk_9A6 = 1;
            temp_v0->unk_1C += temp_v0->unk_24;
            temp_v0->unk_0C.x += temp_v0->unk_18;
            temp_v0->unk_0C.y += temp_v0->unk_1C;
            temp_v0->unk_0C.z += temp_v0->unk_20;
            temp_v0->unk_28.x += temp_v0->unk_2E.x;
            temp_v0->unk_28.y += temp_v0->unk_2E.y;
            temp_v0->unk_28.z += temp_v0->unk_2E.z;
        }
    }
}
