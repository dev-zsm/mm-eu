// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dora.h"

s32 ObjDora_IsHalfHour(u16 time) {
    f32 timeHalfHour = time;

    timeHalfHour -= (CLOCK_TIME_F(0, 30) * (s32)(time / CLOCK_TIME_F(0, 30)));
    if ((timeHalfHour < CLOCK_TIME_F(0, 1)) || (CLOCK_TIME_F(0, 29) < timeHalfHour)) {
        return true;
    }

    return false;
}
