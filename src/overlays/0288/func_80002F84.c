#include "types.h"
typedef struct { u8 pad0[0x198]; f32 a198; } A;
void func_8018142C(f32, f32, f32, s32);
void func_80002F84(s32 a, s32 limb, A *this) {
    if (limb >= 3 && limb < 9) {
        f32 t = this->a198;
        func_8018142C(t, t, t, 1);
    }
}
