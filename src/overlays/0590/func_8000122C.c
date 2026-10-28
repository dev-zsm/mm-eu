// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
f32 func_800FEB84(s16);                             /* extern */
M2C_UNK func_800FFBF8(u8 *, s32, f32, f32);       /* extern */
extern f32 D_80BC87DC;

void func_8000122C(u8 *arg0, u8 *arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 8) {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) -M2C_FIELD(arg0, s16 *, 0x32);
    }
    func_800FFBF8(arg0 + 0x70, M2C_FIELD(arg0, s32 *, 0x2B8), D_80BC87DC, D_80BC87DC);
    func_800FFBF8(arg0 + 0x68, 0x40400000, 0.2f, 0.5f);
    if ((M2C_FIELD(arg0, f32 *, 0x28) > 1000.0f) || (M2C_FIELD(arg0, f32 *, 0x98) > 2000.0f)) {
        func_800B6490(arg0);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x2BE) = (s16) (M2C_FIELD(arg0, s16 *, 0x2BE) + 0x800);
    M2C_FIELD(arg0, f32 *, 0xC4) = (f32) (func_800FEB84(M2C_FIELD(arg0, s16 *, 0x2BE)) * 500.0f);
    func_800B680C(arg0);
    if (((u32) M2C_FIELD(arg1, u32 *, 0x9C) % 43U) == 0) {
        func_800B8C4C(arg0, 0x38B6);
    }
}
