// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80962E70(u8 *, s32);                 /* extern */
M2C_UNK func_80962EDC(u8 *);                      /* extern */
s32 func_809633D8(u8 *);                          /* extern */
M2C_UNK func_80963520(u8 *, s32);                 /* extern */

void func_80000D38(s32 arg0, M2C_UNK arg1, u8 *arg2) {
    s32 temp_v0;

    temp_v0 = (((s16) M2C_FIELD(arg2, s16 *, 0x48) >> 5) & 3) << 5;
    switch (temp_v0) {                              /* irregular */
    case 0x20:
        M2C_FIELD(arg2, s16 *, 0x44) = (s16) (M2C_FIELD(arg2, s16 *, 0x44) + 0x47B);
        M2C_FIELD(arg2, s16 *, 0x46) = (s16) (M2C_FIELD(arg2, s16 *, 0x46) + 0x139);
        break;
    case 0x40:
        M2C_FIELD(arg2, s16 *, 0x44) = (s16) (M2C_FIELD(arg2, s16 *, 0x44) + 0x1A7C);
        M2C_FIELD(arg2, s16 *, 0x46) = (s16) (M2C_FIELD(arg2, s16 *, 0x46) + 0x47B);
        break;
    case 0x60:
        M2C_FIELD(arg2, s16 *, 0x44) = (s16) (M2C_FIELD(arg2, s16 *, 0x44) + 0x3F27);
        M2C_FIELD(arg2, s16 *, 0x46) = (s16) (M2C_FIELD(arg2, s16 *, 0x46) + 0xCA1);
        break;
    }
    func_80962EDC(arg2);
    if (func_809633D8(arg2) == 0) {
        M2C_FIELD(arg2, s16 *, 0x5C) = 0;
    }
    func_80963520(arg2, arg0);
    if (M2C_FIELD(arg2, s16 *, 0x54) != -1) {
        func_80962E70(arg2, arg0);
    }
}
