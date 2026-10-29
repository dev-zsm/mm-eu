#include "types.h"

typedef struct {
    u8 pad0[0xBE];
    s16 unkBE;
    u8 padC0[0x84];
    void *unk144;
    u8 pad148[3];
    u8 unk14B;
    u8 pad14C[2];
    s16 unk14E;
    s16 unk150;
} S;

extern u8 D_80A33048[];

void func_800003E8(S *s) {
    s->unk14E = 0x1E;
    s->unk150 = s->unkBE;
    s->unk14B &= 0xFFFE;
    s->unk144 = D_80A33048;
}
