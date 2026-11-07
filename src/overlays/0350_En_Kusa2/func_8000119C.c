// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

EnKusa2UnkBssSubStruct2* ref_func_80A5C2FC(EnKusa2UnkBssStruct* arg0, f32 arg1, Vec3f* arg2, Vec3f* arg3, Vec3s* arg4,
                                       Vec3s* arg5) {
    Vec3f* temp_a0;
    EnKusa2UnkBssSubStruct2* temp_s0;
    f32 phi_f8;

    temp_s0 = ref_func_80A5C0B8(arg0);
    temp_s0->unk_00 = arg1;
    Math_Vec3f_Copy(&temp_s0->unk_04, arg2);
    Math_Vec3f_Copy(&temp_s0->unk_10, arg3);

    if (arg1 >= 0.35f) {
        temp_s0->unk_1C = (6.0f / 7);
    } else if (arg1 <= 0.1f) {
        temp_s0->unk_1C = 1.0f;
    } else {
        temp_s0->unk_1C = (0.02f / arg1) + 0.8f;
    }

    temp_s0->unk_20 = *arg4;
    temp_s0->unk_26 = *arg5;
    temp_s0->unk_2C = Rand_S16Offset(65, 30);

    return temp_s0;
}
