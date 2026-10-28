// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800E1490(s32, u8 *);                 /* extern */
s32 func_800E1718(s32, u8 *, u8 *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_8013E768(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_80BEEC70(M2C_UNK *, u8 *, u8 *, u8 *); /* extern */
M2C_UNK func_80BEF118(u8 *);                      /* extern */
extern M2C_UNK D_6002498;
extern M2C_UNK D_80BEF438;
extern M2C_UNK D_80BEF448;

void func_8000011C(u8 *arg0, s32 arg1) {
    u8 *sp2C;
    u8 *temp_a1;

    func_800FF8DC(arg0, &D_80BEF448);
    func_800CABA0(arg0, 1);
    func_800CABC4(arg1, arg0, &D_6002498);
    temp_a1 = arg0 + 0x160;
    sp2C = temp_a1;
    func_800E1490(arg1, temp_a1);
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F) != 0) {
        func_800B6490(arg0);
        return;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000000);
    if (func_800E1718(arg1, sp2C, arg0, &D_80BEF438, arg0 + 0x180) == 0) {
        func_800B6490(arg0);
        return;
    }
    func_80BEEC70(&D_80BEF438, arg0 + 0x24, arg0 + 0xBC, sp2C);
    func_8013E768(arg0, arg0 + 0x238, 1);
    func_80BEF118(arg0);
}
