#include "types.h"
#include "m2c_compat.h"
extern f32 D_80A8F824;
void func_800FFAD8(u8 *a, f32 b, f32 c, f32 d, f32 e);

void func_80000ECC(u8 *a, s32 b) {
    func_800FFAD8(a + 0x28, 0.0f, 0.05f, 2.0f, D_80A8F824);
}
