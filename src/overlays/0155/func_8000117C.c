// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80920138(u8 *, s32, M2C_UNK *, M2C_UNK); /* extern */
s32 func_809206C0();                                /* extern */
extern M2C_UNK D_8092089C;

void func_8000117C(u8 *arg0, s32 arg1) {
    if ((func_809206C0() != 0) || (((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 7) & 1)) {
        M2C_FIELD(arg0, s16 *, 0x1C) = (s16) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFF7F);
        func_80920138(arg0, arg1, &D_8092089C, 1);
    }
}
