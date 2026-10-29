#include "types.h"

typedef struct {
    u8 pad0[0x194];
    void *unk194;
    u8 pad198[4];
    s16 unk19C;
    u8 unk19E, unk19F, unk1A0;
} S;

extern u8 D_80B698EC[];

void func_80000F1C(S *s, s32 a1) {
    s->unk19C = 0x3C;
    s->unk19E = 0xFF;
    s->unk19F = 0;
    s->unk1A0 = 0;
    s->unk194 = D_80B698EC;
}
