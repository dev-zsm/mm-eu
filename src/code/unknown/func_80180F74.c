// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math_atan.h"

s16 Math_Atan2S(f32 y, f32 x) {
    s32 angle;

    if (y == 0.0f) {
        if (x >= 0.0f) {
            angle = 0;
        } else {
            angle = 0x8000;
        }
    } else if (x == 0.0f) {
        if (y >= 0.0f) {
            angle = 0x4000;
        } else {
            angle = 0xC000;
        }
    } else if (y >= 0.0f) {
        if (x >= 0.0f) {
            if (y <= x) {
                angle = Math_GetAtan2Tbl(y, x);
            } else {
                angle = 0x4000 - Math_GetAtan2Tbl(x, y);
            }
        } else {
            if (-x < y) {
                angle = Math_GetAtan2Tbl(-x, y) + 0x4000;
            } else {
                angle = 0x8000 - Math_GetAtan2Tbl(y, -x);
            }
        }
    } else if (x < 0.0f) {
        if (-y <= -x) {
            angle = Math_GetAtan2Tbl(-y, -x) + 0x8000;
        } else {
            angle = 0xC000 - Math_GetAtan2Tbl(-x, -y);
        }
    } else {
        if (x < -y) {
            angle = Math_GetAtan2Tbl(x, -y) + 0xC000;
        } else {
            angle = -Math_GetAtan2Tbl(-y, x);
        }
    }
    return angle;
}
