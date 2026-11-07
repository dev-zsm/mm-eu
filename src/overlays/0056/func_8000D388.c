#include "types.h"
typedef struct { u8 pad0[0xAD0]; f32 aD0; u8 pad1[0x14]; s16 aE8; } P;
extern f32 D_801EACA4;
s32 func_80839F50(s32, P *, f32);
void func_8000D388(s32 a, P *p) {
    p->aD0 = 2.0f;
    D_801EACA4 = 2.0f;
    if (func_80839F50(a, p, 120.0f) != 0) {
        p->aE8 = -0xF;
    }
}
