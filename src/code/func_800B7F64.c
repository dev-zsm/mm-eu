#include "types.h"
typedef struct { s32 a, b, c, d, e; } Focus5;
void *Actor_GetFocus(void *a0, u8 *a1) {
    *(Focus5 *)a0 = *(Focus5 *)(a1 + 0x3C);
    return a0;
}
