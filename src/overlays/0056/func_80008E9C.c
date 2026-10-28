// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082DAE8(s32, u8 *, s32);            /* extern */
s32 func_8082E3D0(u8 *);                          /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_808494C4;

void func_80008E9C(u8 *arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_808494C4, 1);
    func_8082DAE8(arg1, arg0, func_8082E3D0(arg0));
    M2C_FIELD(arg0, s16 *, 0xAD4) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
