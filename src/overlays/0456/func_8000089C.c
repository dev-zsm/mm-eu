#include "types.h"

typedef struct { u8 pad0[0x18875]; u8 unk18875; u8 pad18876[4]; u16 unk1887A; u8 pad1887C[3]; u8 unk1887F; } A;
extern u8 D_801EAE45;

void func_8000089C(A *a) {
    a->unk1887A = 0x9C20;
    a->unk1887F = 0x40;
    D_801EAE45 = 0x40;
    a->unk18875 = 0x14;
}
