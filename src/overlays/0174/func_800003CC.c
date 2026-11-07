#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 params; } A;
void func_800E0FAC();
void func_800003CC(A *thisx, s32 play2) {
    s32 play = play2;
    A *this = thisx;
    if (((this->params & 0xF80) >> 7) != 0x1E) {
        func_800E0FAC(play, (u8 *)this + 0x144);
    }
}
