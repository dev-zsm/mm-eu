#include "types.h"

s32 func_800014A8(s32 a0, s32 a1, s32 *a2, s32 a3, s32 a4, u8 *a5) {
    *(s32 *)(a5 + a1 * 4 + 0x1E4) = *a2;
    *a2 = 0;
    return 0;
}
