#include "types.h"
typedef struct { u8 pad0[0x70]; f32 a70; } A;
s32 func_80137070();
void func_808DE078();
void func_8000044C(A *thisx, s32 play) {
    A *this = thisx;
    this->a70 = 0.0f;
    if (func_80137070((u8 *)this + 0x198) != 0) {
        func_808DE078(this);
    }
}
