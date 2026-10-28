// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0FAC(s32, s32, u8 *);            /* extern */
M2C_UNK func_80112D7C(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000CD8(u8 *arg0, s32 arg1) {
    func_800E0FAC(arg1, arg0 + 0x320, arg0);
    if ((((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x780) >> 7) == 5) && (M2C_FIELD(arg0, u16 *, 0x3E4) & 0x2000)) {
        func_80112D7C(arg1, 0x61, arg0);
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100E) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100E) & 0xEF);
    }
}
