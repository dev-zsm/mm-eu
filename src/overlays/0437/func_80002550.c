// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FF72C(u8 *, u8 *);                  /* extern */
M2C_UNK func_80AD2AD0(u8 *, s32);                 /* extern */
s32 func_80AD359C(u8 *, s32);                     /* extern */
M2C_UNK func_80AD3804(u8 *, s32);                 /* extern */

void func_80002550(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x30C)(arg0, arg1);
    func_80AD3804(arg0, arg1);
    if (func_800FF72C(arg0 + 0x24, arg0 + 0x300) >= 100.0f) {
        M2C_FIELD(arg0, u16 *, 0x2CA) = (u16) (M2C_FIELD(arg0, u16 *, 0x2CA) & 0xFFFD);
    }
    if (func_80AD359C(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s16 *, 0x310) = 2;
        func_80AD2AD0(arg0, arg1);
    }
}
