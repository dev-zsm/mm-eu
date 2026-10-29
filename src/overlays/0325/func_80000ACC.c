#include "types.h"

typedef struct {
    u8 pad0[0x70];
    f32 unk70;
    u8 pad74[0x31C];
    void *unk390;
    u8 pad394[4];
    s32 unk398;
    u8 pad39C[0x26];
    s16 unk3C2;
} Ovl0325Actor;

extern u8 D_80A21D30[];
extern s16 D_80A2222C[];

void func_80000ACC(Ovl0325Actor *a) {
    a->unk390 = D_80A21D30;
    a->unk3C2 = D_80A2222C[a->unk398];
    a->unk70 = 0.0f;
}
