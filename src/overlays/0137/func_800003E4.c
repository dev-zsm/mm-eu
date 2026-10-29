#include "types.h"

extern s32 func_80902434();

s32 func_800003E4(void *a0, u8 *a1) {
    return *(s16 *)(a1 + 0xA4) == 0x2F && func_80902434(a0) != 0;
}
