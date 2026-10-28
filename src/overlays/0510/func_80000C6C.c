// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
extern M2C_UNK D_80B622C4;
extern f32 D_80B632F0;

void func_80000C6C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x30A) = 0xA;
    M2C_FIELD(arg0, f32 *, 0x160) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x2BC) = (f32) (func_800FEB84(M2C_FIELD(arg0, s16 *, 0x92)) * -12.0f);
    M2C_FIELD(arg0, f32 *, 0x2C4) = (f32) (func_800FEB44(M2C_FIELD(arg0, s16 *, 0x92)) * -12.0f);
    M2C_FIELD(arg0, f32 *, 0x2FC) = (f32) D_80B632F0;
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x19);
    func_800B8C4C(arg0, 0x3988);
    M2C_FIELD(arg0, M2C_UNK **, 0x2AC) = &D_80B622C4;
}
