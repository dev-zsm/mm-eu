// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9B160(BgHakuginPostUnkStruct* unkStruct, PlayState* play) {
    s32 i;

    for (i = 0; i < unkStruct->count; i++) {
        Math_Vec3f_Copy(&unkStruct->unk_0000[i].unk_14, &unkStruct->unk_0000[i].unk_08);
        unkStruct->unk_0000[i].unk_20 = 0.0f;
        unkStruct->unk_0000[i].unk_24 = 0.0f;
        unkStruct->unk_0000[i].unk_34 = 1;
        if (ref_D_80A9D880[unkStruct->unk_0000[i].unk_00].unk_04 != 0) {
            Flags_UnsetSwitch(play, unkStruct->unk_0000[i].switchFlag);
        }
    }
}
