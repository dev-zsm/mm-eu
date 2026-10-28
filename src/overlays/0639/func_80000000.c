// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_60014D8;
extern M2C_UNK D_80BFCFA0;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80BFCFA0);
    M2C_FIELD(arg0, f32 *, 0xFC) = 4000.0f;
    func_800CABA0(arg0, 1);
    func_800CABC4(arg1, arg0, &D_60014D8);
}
