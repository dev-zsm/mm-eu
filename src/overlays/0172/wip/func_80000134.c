#include "types.h"

void func_80000134(u8 *a0, s32 a1) {
    u8 *v1;
    u8 *v0;
    s16 t;

    v1 = *(u8 **)(a0 + 0x120);
    v0 = v1;
    if (v1 == 0) {
        return;
    }
    if (*(s32 *)(v1 + 0x138) == 0) {
        return;
    }
    t = *(s16 *)(v1 + 0x290);
    if (t > 0) {
        *(s16 *)(v0 + 0x290) = t - 1;
    }
}
