// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

s32 ref_func_8093EEDC(EnGoroiwa* this) {
    Vec3s* temp_v1 = &this->pathPoints[this->unk_1D8];
    Vec3s* temp_v0 = &this->pathPoints[this->unk_1D6];

    if ((temp_v1->x == temp_v0->x) && (temp_v1->z == temp_v0->z)) {
        if (temp_v0->y < temp_v1->y) {
            return 1;
        }
        return -1;
    }
    return 0;
}
