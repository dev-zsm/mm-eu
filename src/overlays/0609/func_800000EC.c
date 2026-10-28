// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6580(s32, u8 *);                 /* extern */
s32 func_8012FA08(s32, u8);                         /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_60031F8;
extern M2C_UNK D_80BDC428;
extern M2C_UNK D_80BDC5B4;
extern M2C_UNK D_80BDEDA0;

void func_800000EC(u8 *arg0, s32 arg1) {
    u8 *sp34;
    u8 *temp_a1;

    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, u8 *, 0x24A)) != 0) {
        M2C_FIELD(arg0, u8 *, 0x1E) = (u8) M2C_FIELD(arg0, u8 *, 0x24A);
        func_800B6580(arg1, arg0);
        temp_a1 = arg0 + 0x144;
        sp34 = temp_a1;
        func_80136ED0(arg1, temp_a1, &D_60031F8, &D_80BDEDA0, arg0 + 0x188, arg0 + 0x1E8, 0x10);
        func_801378E0(sp34, &D_80BDEDA0);
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80BDC428;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80BDC5B4;
    }
}
