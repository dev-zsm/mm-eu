#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 params; } A;
void func_800E0FAC();
void func_800000BC(A *thisx, s32 play2) {
    s32 play = play2;
    A *this = thisx;
    s32 t = this->params & 0xFF;
    if (t != 0x40 && t != 0x41) {
        func_800E0FAC(play, (u8 *)this + 0x144);
    }
}
