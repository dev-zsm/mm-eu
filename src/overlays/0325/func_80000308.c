// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

void ref_func_80A3C7E8(ObjVspinyroll* this) {
    f32 phi_f2;
    s32 i;
    s32 j;
    f32 tempf;
    s32 index = ref_D_80A3D450[OBJVSPINYROLL_GET_4000(&this->dyna.actor)] * 120.0f * (1.0f / 58.0f);

    index += 2;
    this->unk_1A8.unk_1E4 = index * 4;

    tempf = ((ref_D_80A3D450[OBJVSPINYROLL_GET_4000(&this->dyna.actor)] * 120.0f) - 2.0f) / (index - 1);
    phi_f2 = 1.0f;

    for (i = 0, j = 0; i < this->unk_1A8.unk_1E4; i++) {
        this->unk_1A8.unk_000[i].unk_00.x = ref_D_80A3D4C4[j];
        this->unk_1A8.unk_000[i].unk_00.y = phi_f2;
        this->unk_1A8.unk_000[i].unk_00.z = ref_D_80A3D4B4[j];

        j++;
        if (j >= 4) {
            j = 0;
            phi_f2 += tempf;
        }
    }
}
