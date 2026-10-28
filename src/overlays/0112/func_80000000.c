// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6004240;
extern M2C_UNK D_808D6CC0;
extern M2C_UNK D_808D6F00;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_808D6F00);
    func_800CABA0(arg0, 1);
    func_800CABC4(arg1, arg0, &D_6004240);
    M2C_FIELD(arg0, s16 *, 0x1C) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_808D6CC0;
}
