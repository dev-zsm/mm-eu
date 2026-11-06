// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

EnKusa2UnkBssSubStruct* ref_func_80A5C104(EnKusa2UnkBssStruct* arg0, Vec3f* arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5) {
    static s32 ref_D_80A5EB48 = 0;
    EnKusa2UnkBssSubStruct* ptr = ref_func_80A5C074(arg0);
    f32 sp20;
    f32 temp_f6;

    Math_Vec3f_Copy(&ptr->unk_00, arg1);
    Math_Vec3f_Copy(&ptr->unk_0C, &gZeroVec3f);

    ptr->unk_18 = arg2;
    ptr->unk_1C = arg3;
    ptr->unk_20 = arg4;
    ptr->unk_22 = arg5;

    ref_D_80A5EB48++;
    if (ref_D_80A5EB48 >= 3) {
        ref_D_80A5EB48 = 0;
        ptr->unk_26 = Rand_S16Offset(40, 40);
    } else {
        ptr->unk_26 = Rand_S16Offset(30, 20);
    }

    ptr->unk_24 = ptr->unk_26 - 20;
    sp20 = 1.0f / ptr->unk_24;
    ptr->unk_28 = ref_func_80A5C70C;
    ptr->unk_2C = 0.0f;
    ptr->unk_30 = 0.0f;
    temp_f6 = Rand_ZeroOne() * 60.0f;
    ptr->unk_34 = (temp_f6 + 20.0f) * 0.05f;
    ptr->unk_38 = (temp_f6 + 20.0f) * sp20;
    ptr->unk_3C = 40.0f;
    ptr->unk_40 = -1.5f;
    ptr->unk_44 = -50.0f * sp20;
    ptr->unk_48 = 140.0f;
    ptr->unk_4C = SQ(140.0f);
    ptr->unk_50 = 819.2f;
    ptr->unk_54 = 327.68f;
    ptr->unk_58 = 2.5f;
    ptr->unk_5C = 0.05f;
    ptr->unk_60 = 3.5f * sp20;
    ptr->unk_64 = 0.35f;
    ptr->unk_68 = 0.0875f;
    ptr->unk_6C = 160.0f;
    ptr->unk_70 = SQ(160.0f);
    ptr->unk_74 = 204.8f;
    ptr->unk_78 = 100.0f;
    ptr->unk_7C = 327.68f;
    return ptr;
}
