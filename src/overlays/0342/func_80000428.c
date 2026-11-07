#include "types.h"
#include "m2c_compat.h"
void func_8018132C(f32 a, f32 b, f32 c, s32 d);

s32 func_80000428(s32 a, s32 limb, s32 c, s32 d, s32 e, u8 *thisx) {
    if (limb == 1) {
        func_8018132C(0.0f, M2C_FIELD(thisx, f32 *, 0xC4), 0.0f, 1);
    }
    return 0;
}
