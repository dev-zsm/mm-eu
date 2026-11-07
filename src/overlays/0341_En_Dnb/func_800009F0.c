// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

s32 ref_func_80A507C0(EnDnbUnkStruct* arg0, Vec3f arg1, Vec3f arg2, u8 arg3, f32 arg4, f32 arg5) {
    s32 i;
    s32 ret = 0;

    for (i = 0; i < 256; i++, arg0++) {
        if (arg0->isEnabled == false) {
            arg0->isEnabled = true;
            arg0->unk_01 = arg3;
            arg0->unk_02 = arg3;
            arg0->unk_0C = arg1;
            arg0->unk_18 = arg2;
            arg0->unk_04 = arg4;
            arg0->unk_08 = arg5;
            arg0->unk_24 = 255.0f;
            ret = 1;
            break;
        }
    }
    return ret;
}
