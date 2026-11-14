// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x2B0];
    s32 unk2B0;
    u8 pad2B4[0x2D2 - 0x2B4];
    s16 unk2D2;
} Act;

void func_800E09D8();
void func_800F1D6C();
s32 func_800F1E2C();
void func_801A3D9C();

void func_80000590(Act *this, void *play) {
    if (this->unk2B0 == 0) {
        func_801A3D9C();
        func_800E09D8(play, (u8 *)this + 0xF34);
    }
    if (func_800F1E2C() == this->unk2D2) {
        func_800F1D6C(this->unk2D2);
    }
}
