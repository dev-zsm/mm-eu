#include "types.h"

typedef struct {
    u8 pad0[0x160];
    void *unk160;
    u8 pad164[0x17];
    u8 unk17B;
    u8 unk17C;
} S;

extern u8 D_80B63DF0[];

void func_80000644(S *s) {
    s->unk17C &= 0xFFF8;
    s->unk17B = 0;
    s->unk17C |= 1;
    s->unk160 = D_80B63DF0;
}
