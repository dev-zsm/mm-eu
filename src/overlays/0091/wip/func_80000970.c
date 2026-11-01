#include "types.h"

extern u8 D_808AFD4C[];

typedef struct {
    u8 pad0[0x32];
    s16 unk32;
    u8 pad34[0x8A];
    s16 unkBE;
    u8 pad_C0[0x170];
    u8 *unk230;
    s16 unk234;
    s16 unk236;
    u8 pad238[8];
    f32 unk240;
} Actor91;

void func_80000970(Actor91 *a) {
    a->unk236 = 0x28;
    a->unk32 = a->unkBE;
    a->unk230 = D_808AFD4C;
    a->unk240 = 0.0f;
}
