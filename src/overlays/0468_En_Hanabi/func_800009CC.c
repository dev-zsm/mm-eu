// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void ref_func_80B235CC(EnHanabi* this, Vec3f* arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->unk_4640); i++) {
        if (this->unk_4640[i] == 0) {
            this->unk_4648[i] = arg2;
            Lights_PointNoGlowSetInfo(&this->unk_4608[i], arg1->x, arg1->y, arg1->z, ref_D_80B23C2C[arg2],
                                      ref_D_80B23C2C[arg2 + 1], ref_D_80B23C2C[arg2 + 2], 0x3E8);
            this->unk_4640[i] = 20;
            break;
        }
    }
}
