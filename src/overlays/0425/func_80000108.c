// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
f32 func_800FFAD8(u8 *, f32, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_80ABF8D4(u8 *);                          /* extern */

void func_80000108(Actor *thisx) {
    f32 var_f0;

    if (M2C_FIELD(thisx, s16 *, 0x160) == 0) {
        if (func_80ABF8D4(thisx) != 0) {
            var_f0 = M2C_FIELD(thisx, f32 *, 0xC) + -10.0f;
        } else {
            var_f0 = M2C_FIELD(thisx, f32 *, 0xC) + 10.0f;
        }
    } else {
        var_f0 = M2C_FIELD(thisx, f32 *, 0xC) + 25.0f;
    }
    if (func_800FFAD8((u8 *)thisx + 0x28, var_f0, 0x3D4CCCCD, 0x3F800000, 0.5f) > 1.0f) {
        if (M2C_FIELD(thisx, s16 *, 0x160) == 1) {
            func_800B8D94(thisx, 0x213B);
            return;
        }
        func_800B8D94(thisx, 0x213B);
    }
}
