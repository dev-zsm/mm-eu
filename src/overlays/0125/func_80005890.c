// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(s32, s16, M2C_UNK);           /* extern */
s32 func_80137C58(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_808E62E8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808E9924(u8 *);                      /* extern */

void func_80005890(u8 *arg0, M2C_UNK arg1) {
    s16 sp26;

    func_800FEC70(arg0 + 0x2D0, M2C_FIELD(arg0, s16 *, 0x92), 0x300);
    if ((func_80137C58(arg0 + 0x144, 0x41D80000) != 0) && (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0xA44), s16 *, 0x1C) == 0xA)) {
        func_808E62E8(arg0, 0x395E);
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0xA44), s16 *, 0x1C) = 0xB;
    }
    if (M2C_FIELD(arg0, u8 *, 0x2B2) != 0) {
        sp26 = M2C_FIELD(arg0, s16 *, 0x2BA);
        func_808E9924(arg0);
        M2C_FIELD(arg0, s16 *, 0x2BA) = sp26;
    }
}
