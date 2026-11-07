#include "types.h"
typedef struct { u8 pad0[0x4FC]; s32 a4FC; } A;
void func_80137070();
s32 func_80137C58();
void func_809D4EFC();
void func_800021D8(A *this, s32 play) {
    func_80137070((u8 *)this + 0x3C8);
    if (func_80137C58((u8 *)this + 0x3C8, this->a4FC) != 0) {
        func_809D4EFC(this, play);
    }
}
