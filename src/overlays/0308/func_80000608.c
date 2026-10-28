// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80137C58(s32, s32);                        /* extern */
M2C_UNK func_80A10FAC(u8 *);                      /* extern */

void func_80000608(u8 *arg0, M2C_UNK arg1) {
    if (func_80137C58(arg0 + 0x144, M2C_FIELD(arg0, s32 *, 0x154)) != 0) {
        func_80A10FAC(arg0);
    }
    if (M2C_FIELD(arg0, s16 *, 0x1F0) == 1) {
        func_800FFCBC(arg0 + 0x1F2, -0x8000, 5, 0x1000, 0x100);
    }
    M2C_FIELD(arg0, s16 *, 0x1D8) = (s16) (M2C_FIELD(arg0, s16 *, 0x1D8) + 1);
}
