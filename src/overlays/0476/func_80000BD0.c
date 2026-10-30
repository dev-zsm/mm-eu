#include "types.h"

typedef struct {
    u8 pad0[4];
    u32 unk4;
    u8 pad8[0x32 - 8];
    s16 unk32;
    u8 pad34[0x70 - 0x34];
    f32 unk70;
    u8 pad74[0xBE - 0x74];
    s16 unkBE;
    u8 padC0[0x11F - 0xC0];
    u8 unk11F;
    u8 pad120[0x188 - 0x120];
    void *unk188;
    u8 pad18C[2];
    s16 unk18E;
} A;

extern u8 D_80B12030[];
void func_80000BD0(A *a) {
    a->unk70 = 0.0f;
    a->unk32 = a->unkBE;
    a->unk18E = 0;
    a->unk11F = 0xFF;
    a->unk4 &= ~1;
    a->unk188 = D_80B12030;
}
