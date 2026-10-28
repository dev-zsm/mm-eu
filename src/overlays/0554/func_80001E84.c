// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B83C0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80151DF4(M2C_UNK, s32, u8 *);        /* extern */
s16 func_80BA1820(u8 *, M2C_UNK);                 /* extern */
s32 func_80BA286C(u8 *, M2C_UNK);                 /* extern */
extern M2C_UNK D_80BA3798;

void func_80001E84(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    if (((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) == 8) || (func_80BA286C(arg0, arg1) == 0)) {
        if (func_800B8254(arg0, arg1) != 0) {
            M2C_FIELD(arg0, u16 *, 0x1DC) = (u16) (M2C_FIELD(arg0, u16 *, 0x1DC) | 0x10);
            temp_v0 = func_80BA1820(arg0, arg1);
            M2C_FIELD(arg0, s16 *, 0x304) = temp_v0;
            func_80151DF4(arg1, temp_v0 & 0xFFFF, arg0);
            M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80BA3798;
        } else if ((M2C_FIELD(arg0, f32 *, 0x98) < 250.0f) || (M2C_FIELD(arg0, u8 *, 0x114) != 0)) {
            func_800B83C0(arg0, arg1);
        }
        func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x16), 5, 0x1000, 0x100);
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    }
}
