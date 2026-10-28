// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80B7DBB4(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B7DD38;

void func_80002B58(u8 *arg0, s32 arg1) {
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x16), 2, 0x400, 0x100);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7DD38;
        func_80B7DBB4(arg0, arg1);
        return;
    }
    if ((func_800B70A4(arg0, 0x3000, arg1) != 0) && (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f)) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
}
