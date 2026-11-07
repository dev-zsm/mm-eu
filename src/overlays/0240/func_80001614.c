#include "types.h"
typedef struct { u8 pad0[0x154]; s32 a154; } A;
s32 func_80137C58();
void func_80979AE8();
void func_80001614(A *thisx, s32 play) {
    A *this = thisx;
    if (func_80137C58((u8 *)this + 0x144, this->a154) != 0) {
        func_80979AE8(this, play);
    }
}
