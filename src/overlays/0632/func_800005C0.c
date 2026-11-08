#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0632.h"
void func_80181A3C(s16 a, s32 b);
void func_80182C08(f32 a, u8 *b);

void func_800005C0(s32 a, s32 limb, u8 *c) {
    if (limb == 5) {
        func_80181A3C(0x400 - M2C_FIELD(c, s16 *, 0x2AE), 1);
        func_80182C08(500.0f, c + 0x3C);
    }
}
