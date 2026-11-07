#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 a1C; } Q;
typedef struct { u8 pad0[0x188]; void* a188; u8 pad1[0x162]; s16 a2EE; u8 pad2[0x3F4]; Q* q[20]; } A;
extern u8 D_808C6BC8[];
void func_80002524(A *this) {
    s32 i;
    for (i = 0; i < 20; i++) {
        this->q[i]->a1C = 5;
    }
    this->a2EE = 0;
    this->a188 = D_808C6BC8;
}
