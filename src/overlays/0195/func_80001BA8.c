// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80958C30(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_809591E8(u8 *);                      /* extern */
M2C_UNK func_80959208(u8 *);                      /* extern */
M2C_UNK func_80959280(u8 *);                      /* extern */
s32 func_80959764(u8 *, s32);                     /* extern */
s32 func_8095984C(u8 *);                          /* extern */
extern M2C_UNK D_8095A6D8;
extern M2C_UNK func_8095A300;

void func_80001BA8(u8 *arg0, s32 arg1) {
    f32 sp24;

    sp24 = M2C_FIELD(arg0, f32 *, 0x15C) / (M2C_FIELD(arg0, f32 *, 0x158) - 1.0f);
    if (sp24 == 1.0f) {
        func_80959208(arg0);
    }
    if (func_80959764(arg0, arg1) != 0) {
        func_80959280(arg0);
        func_80958C30(arg0, &D_8095A6D8);
        return;
    }
    if (func_8095984C(arg0) != 0) {
        func_809591E8(arg0);
        func_80958C30(arg0, &func_8095A300);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x68) = (f32) (4.0f * sp24);
}
