// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(s32);                         /* extern */
f32 func_800FEB84(s16);                             /* extern */
extern f32 D_80B9CFB0;
extern u8 *D_80B9D1F0;
extern f32 D_80B9D1F4;

void func_800013C0(s32 arg0, u8 *arg1) {
    D_80B9D1F4 = (func_800FEB84((s16) (M2C_FIELD(arg1, s32 *, 0x18840) * 0x3000)) * D_80B9CFB0) + 1.0f;
    if (M2C_FIELD(D_80B9D1F0, u8 *, 0x1F6) == 0xB) {
        func_800B6490(arg0);
    }
}
