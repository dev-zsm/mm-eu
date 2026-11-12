#include "types.h"
#include "m2c_compat.h"

s16 func_800B6A58(u8 *, s32);                     /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FEE3C(s32, f32, M2C_UNK);       /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80137C58(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80B29BC0(u8 *, s32);                 /* extern */
M2C_UNK func_80B30240(u8 *);                      /* extern */
extern s32 D_80B3513C;

void func_80007DB8(u8 *arg0, s32 arg1) {
    u8 *temp_a0;

    func_800FEE3C(arg0 + 0x70, 0, 0x3F800000);
    func_800FFCBC(arg0 + 0x32, func_800B6A58(arg0, D_80B3513C), 5, 0x1388, 0x64);
    func_80B29BC0(arg0, arg1);
    temp_a0 = arg0 + 0x144;
    if ((func_80137C58(temp_a0, 0x41500000) != 0) || (func_80137C58(temp_a0, 0x41980000) != 0)) {
        func_800B8C4C(arg0, 0x2910);
    }
    if (M2C_FIELD(arg0, s8 *, 0x29C) != 0) {
        func_80B30240(arg0);
    }
}
