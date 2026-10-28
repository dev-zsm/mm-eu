// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6580(s32, u8 *);                 /* extern */
s32 func_8012FA08(s32, s8);                         /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK, u8 *, u8 *, s32); /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6004C30;
extern M2C_UNK D_6004E98;
extern M2C_UNK D_80B2CFAC;
extern M2C_UNK D_80B32EE0;

void func_80004814(u8 *arg0, s32 arg1) {
    u8 *sp34;
    u8 *temp_a1;

    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, s8 *, 0x2F4)) != 0) {
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) M2C_FIELD(arg0, s8 *, 0x2F4);
        func_800B6580(arg1, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B2CFAC;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B32EE0;
        temp_a1 = arg0 + 0x144;
        sp34 = temp_a1;
        func_80136ED0(arg1, temp_a1, &D_6004C30, 0, arg0 + 0x188, arg0 + 0x212, 6);
        func_801378E0(sp34, &D_6004E98);
    }
}
