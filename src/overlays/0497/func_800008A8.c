#include "types.h"

typedef struct {
    u8 pad0[0x1CCC];
    u8 *unk1CCC;
} G;

s32 func_80B4AEBC();

void func_800008A8(void *a, G *g) {
    u8 *p = g->unk1CCC;

    if (func_80B4AEBC(a) == 1) {
        *(f32 *)(p + 0xAC0) = 700.0f;
    }
}
