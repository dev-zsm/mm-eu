// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BBED8(s32, s32, u8 *, M2C_UNK);   /* extern */
M2C_UNK func_800E2318(s32, s32, u8 *);            /* extern */
M2C_UNK func_809FCDB0(u8 *);                      /* extern */

void func_80000F2C(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x3B4) == 0) {
        M2C_FIELD(arg0, s16 *, 0x410) = 0x32;
        M2C_FIELD(arg0, s16 *, 0x412) = 0xA;
        func_800BBED8(arg1, arg1 + 0x1CA0, arg0, 6);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~5);
        func_809FCDB0(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x39C) == 1) {
        M2C_FIELD(arg0, s16 *, 0x410) = 0x50;
        M2C_FIELD(arg0, s16 *, 0x412) = 0x32;
        func_800E2318(arg1, arg1 + 0x18884, arg0 + 0x3D0);
    }
}
