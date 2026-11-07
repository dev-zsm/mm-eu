#include "types.h"
typedef struct { u8 pad0[0x14C]; u8 a14C; } A;
void func_800E0FAC();
void EnKanban_Destroy(A *thisx, s32 play2) {
    s32 play = play2;
    A *this = thisx;
    if (this->a14C == 0) {
        func_800E0FAC(play, (u8 *)this + 0x1A4);
    }
}
