// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80BED06C(u8 *, s32);                 /* extern */
extern M2C_UNK D_60022AC;
extern M2C_UNK D_80BECB64;
extern M2C_UNK D_80BED080;
extern M2C_UNK D_80BED450;

void func_800006EC(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    func_800FF8DC(arg0, &D_80BED450);
    func_800B6564(arg0, 0x3DCCCCCD);
    M2C_FIELD(arg0, s32 *, 0x744) = 0;
    func_800CABA0(arg0, 0);
    func_800CABC4(arg1, arg0, &D_60022AC);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C) & 0xF;
    switch (temp_v0) {                              /* irregular */
    case 0:
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BECB64;
        return;
    case 1:
        func_80BED06C(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BED080;
        return;
    default:
        func_800B6490(arg0);
        return;
    }
}
