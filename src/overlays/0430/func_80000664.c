// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80AC4CB4(u8 *, s32);                 /* extern */
extern M2C_UNK D_80AC4D40;

void func_80000664(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AC4D40;
        M2C_FIELD(arg0, u16 *, 0x220) = (u16) (M2C_FIELD(arg0, u16 *, 0x220) | 1);
        if (M2C_FIELD(arg0, u16 *, 0x116) == 0) {
            func_80AC4CB4(arg0, arg1);
        }
    } else if ((M2C_FIELD(arg0, f32 *, 0x98) < 150.0f) && (func_800B70A4(arg0, 0x3000, arg1) != 0)) {
        func_800B8398(arg0, arg1, 0x43200000);
        M2C_FIELD(arg0, u16 *, 0x220) = (u16) (M2C_FIELD(arg0, u16 *, 0x220) | 1);
    } else {
        M2C_FIELD(arg0, u16 *, 0x220) = (u16) (M2C_FIELD(arg0, u16 *, 0x220) & 0xFFFE);
    }
    if (M2C_FIELD(arg0, s16 *, 0x18) != 0) {
        func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 6, 0x1838, 0x64);
    } else {
        func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x16), 6, 0x1838, 0x64);
    }
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
}
