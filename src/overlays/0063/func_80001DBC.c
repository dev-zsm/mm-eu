#include "types.h"
typedef struct { u8 pad0[0xBE]; s16 aBE; } Q;
typedef struct { u8 pad0[0x1C]; s16 a1C; u8 pad1[0xA0]; s16 aBE; u8 pad2[0x64]; Q* q; u8 pad3[0x180]; void* a2A8; } A;
extern u8 D_6000994[];
extern u8 D_8086B2BC[];
void func_801377D0();
void func_80001DBC(A *thisx) {
    A *this = thisx;
    func_801377D0((u8 *)this + 0x144, D_6000994, this);
    this->aBE = this->q->aBE;
    this->a1C = 3;
    this->a2A8 = D_8086B2BC;
}
