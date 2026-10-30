#include "types.h"

typedef struct {
    u8 pad0[0x30];
    s16 unk30;
    s16 unk32;
    u8 pad34[0xBE - 0x34];
    s16 unkBE;
    u8 padC0[0x1D0 - 0xC0];
    void *unk1D0;
} A;

extern u8 D_808ACB4C[];
s16 func_800B6B2C();

void func_80000AC8(A *a) {
    a->unk32 = a->unkBE;
    a->unk30 = -func_800B6B2C(a, (u8 *)a + 0x1F4);
    a->unk1D0 = D_808ACB4C;
}
