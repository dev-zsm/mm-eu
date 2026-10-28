// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E7BB8(u8 *, u8 *);              /* extern */
extern M2C_UNK D_80BC6E88;
extern M2C_UNK D_80BC6F90;

void func_80000000(u8 *arg0, s32 arg1) {
    u8 *sp24;
    u8 *temp_a1;

    func_800B6564(arg0, 0x3F800000);
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80BC6E88;
    temp_a1 = arg0 + 0x144;
    sp24 = temp_a1;
    func_800E1134(arg1, temp_a1, arg0, &D_80BC6F90);
    func_800E7BB8(arg0, temp_a1);
    if (func_800B5B20(arg1, (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFE00) >> 9) != 0) {
        func_800B6490(arg0);
    }
}
