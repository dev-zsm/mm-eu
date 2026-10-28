// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8082F2D4(u8 *);                          /* extern */
s32 func_80836AA8(s32, u8 *, M2C_UNK);            /* extern */
M2C_UNK func_80836DE0(s32, u8 *, M2C_UNK, s32);   /* extern */
s32 func_80836F24(u8 *);                          /* extern */

void func_80009E94(s32 arg0, u8 *arg1) {
    if (func_8082F2D4(arg1) == 0) {
        M2C_FIELD(arg1, s32 *, 0xA70) = (s32) (M2C_FIELD(arg1, s32 *, 0xA70) | 0x20);
    }
    if ((func_80836F24(arg1) != 0) && (func_80836AA8(arg0, arg1, 0x6814) != 0)) {
        func_80836DE0(arg0, arg1, 0x41A00000, (s32) (M2C_FIELD(arg1, f32 *, 0x68) * 50.0f));
    }
}
