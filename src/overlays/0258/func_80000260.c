#include "types.h"
typedef struct { u8 pad0[0x35A]; s16 a35A; } A;
extern s32 D_8098D9C0[];
void func_800E09D8();
void func_80000260(A *this, s32 play) {
    func_800E09D8(play, (u8 *)this + 0x510);
    D_8098D9C0[this->a35A] = 0;
}
