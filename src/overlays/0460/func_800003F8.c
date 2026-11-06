// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

s32 ref_func_80B12D78(ObjDhouse* this) {
    s32 i;
    ObjDhouseStruct2* ptr2 = &this->unk_240[0];
    s32 count = 0;
    ObjDhouseStruct2* ptr22 = &this->unk_240[1];

    for (i = 1; i < ARRAY_COUNT(this->unk_240); i++, ptr22++) {
        if (ptr22->unk_28 < ptr2->unk_28) {
            ptr2 = ptr22;
            count = i;
        }
    }

    return count;
}
