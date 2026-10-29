#include "types.h"

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10[0x18];
    f32 unk28;
    u8 pad2C[0x118];
    void *unk144;
} S;

extern u8 D_80B1C0BC[];
extern f32 D_80B1D8A0;

void func_800002E4(S *s) {
    s->unk28 = s->unkC - D_80B1D8A0;
    s->unk144 = D_80B1C0BC;
}
