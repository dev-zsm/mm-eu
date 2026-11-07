#include "types.h"

typedef struct {
    u8 pad0[0x194];
    void *unk194;
    u8 pad198[4];
    s16 unk19C;
    u8 unk19E;
    u8 unk19F;
    u8 unk1A0;
} Ovl0516Actor;

extern u8 D_80B69C40[];

void func_80001270(Ovl0516Actor *a, s32 b) {
    a->unk19C = 0x3C;
    a->unk19E = 0;
    a->unk19F = 0xFF;
    a->unk1A0 = 0;
    a->unk194 = D_80B69C40;
}
