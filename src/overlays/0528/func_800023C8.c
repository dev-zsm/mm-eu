// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80B7CE98(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B7D448;

void func_800023C8(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, u16 *, 0x2F2) = (u16) (M2C_FIELD(arg0, u16 *, 0x2F2) & 0xFFF7);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7D448;
        func_80B7CE98(arg0, arg1);
        return;
    }
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) && (func_800B70A4(arg0, 0x3000, arg1) != 0) && (func_800B7164(arg0, 0x7000) != 0)) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
}
