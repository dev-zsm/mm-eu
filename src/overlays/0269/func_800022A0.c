#include "types.h"
typedef struct { u8 pad0[0xF37]; u8 f37; } G;
extern G D_801E6EF0;
typedef struct { u8 pad0[0x2D2]; u16 a2D2; } A;
void func_800E0FAC();
void func_800022A0(A *thisx, s32 play2) {
    A *this = thisx;
    s32 play = play2;
    if (!(this->a2D2 & 0x20)) {
        D_801E6EF0.f37 &= 0xFE;
    }
    func_800E0FAC(play, (u8 *)this + 0x18C);
}
