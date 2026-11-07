#include "types.h"
typedef struct { u8 pad0[0x90]; u16 a90; } A;
s32 func_80137070();
void func_8089BAB8();
void func_80001B18(A *thisx, s32 play) {
    A *this = thisx;
    func_80137070((u8 *)this + 0x144);
    if (this->a90 & 1) {
        func_8089BAB8(this);
    }
}
