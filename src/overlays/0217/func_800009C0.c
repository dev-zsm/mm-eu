#include "types.h"

s32 func_800009C0(void *a0, s32 a1, s32 a2) {
    *(f32 *)((u8 *)a0 + 0x1C) = (f32)*(s16 *)((u8 *)a0 + 0x42) * 0.00390625f + *(f32 *)((u8 *)a0 + 0x1C);
    return 1;
}
