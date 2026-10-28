// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B4A5C(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_800B6580(s32, u8 *);                 /* extern */
s32 func_8012FA08(s32, s8);                         /* extern */
M2C_UNK func_80136ED0(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_80B28DAC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B29224(u8 *, s32);                 /* extern */
M2C_UNK func_80B29C88();                            /* extern */
M2C_UNK func_80B29E9C(u8 *);                      /* extern */
M2C_UNK func_80B2A934(u8 *, M2C_UNK *, M2C_UNK, M2C_UNK *, s32, M2C_UNK *, s32, f32, f32, f32); /* extern */
M2C_UNK func_80B2D4E4(u8 *);                      /* extern */
extern M2C_UNK D_6009E58;
extern M2C_UNK D_6013928;
extern M2C_UNK D_801C9EEC;
extern M2C_UNK D_80B2DE20;
extern M2C_UNK D_80B33054;
extern M2C_UNK D_80B337C0;
extern M2C_UNK D_80B33830;
extern f32 D_80B33C34;
extern f32 D_80B33C38;

void func_80005600(u8 *arg0, s32 arg1) {
    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, s8 *, 0x2F4)) != 0) {
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) M2C_FIELD(arg0, s8 *, 0x2F4);
        func_800B6580(arg1, arg0);
        func_80B29C88();
        M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B2DE20;
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80B33054;
        M2C_FIELD(arg0, s16 *, 0x116) = 0x3330;
        func_80136ED0(arg1, arg0 + 0x144, &D_6013928, &D_6009E58, arg0 + 0x188, arg0 + 0x212, 0x17);
        func_80B2A934(arg0 + 0x324, &D_80B337C0, 6, &D_80B33830, 2, &D_801C9EEC, 0x64, D_80B33C34, D_80B33C38, D_80B33C34);
        func_80B29224(arg0, arg1);
        func_80B28DAC(arg0, 0);
        func_800B4A5C(arg1, arg0, 0x42480000);
        func_80B29E9C(arg0);
        func_80B2D4E4(arg0);
    }
}
