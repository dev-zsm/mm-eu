// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0594.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_8013DA3C(s32, s16, u8 *, u8 *);        /* extern */

void func_80000000(Actor *thisx) {
    s32 temp_a0;

    if (M2C_FIELD(thisx, s16 *, 0x27A) != -1) {
        temp_a0 = M2C_FIELD(thisx, s32 *, 0x258);
        if ((temp_a0 != 0) && (func_8013DA3C(temp_a0, M2C_FIELD(thisx, s16 *, 0x25C), (u8 *)thisx + 0x268, thisx) == 0)) {
            func_800B6490(thisx);
        }
    }
}
