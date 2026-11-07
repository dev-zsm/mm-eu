#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 params; u8 pad1[0x126]; void* a144; u8 pad2[0x4C]; u8 a194; } A;
extern u8 D_8091AC58[];
extern u8 D_8091AC94[];
void func_80001740(A *this) {
    s32 t = this->params & 3;
    if (t != 1) {
        if (t == 2 || t == 3) {
            this->a144 = D_8091AC94;
        }
    } else {
        this->a144 = D_8091AC58;
    }
    this->a194 = 0;
}
