#include "types.h"
f32 func_801647D0(u8 *a0) {
    if (a0[2] != 2) {
        return 38.0f - (*(f32 *)(a0 + 0x40) - *(f32 *)(a0 + 0x28));
    }
    switch (a0[0x14B]) {
    case 3:
        return -8.0f;
    case 1:
        return 23.0f;
    case 2:
        return 27.0f;
    case 0:
        return 17.0f;
    default:
        return 0.0f;
    }
}
