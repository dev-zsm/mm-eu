// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void ref_func_80B234C8(EnHanabi* this) {
    s16 phi_v1;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->unk_4640); i++) {
        if (this->unk_4640[i] > 0) {
            this->unk_4640[i]--;
            if (this->unk_4640[i] == 0) {
                phi_v1 = -1;
            } else {
                if (this->unk_4640[i] >= 0xA) {
                    phi_v1 = 0x3E8;
                } else {
                    phi_v1 = this->unk_4640[i] * 0x64;
                }

                if (this->actor.home.rot.x >= 0x259) {
                    phi_v1 *= 2;
                }
            }

            Lights_PointSetColorAndRadius(&this->unk_4608[i], ref_D_80B23C2C[this->unk_4648[i]],
                                          ref_D_80B23C2C[this->unk_4648[i] + 1], ref_D_80B23C2C[this->unk_4648[i] + 2], phi_v1);
        }
    }
}
