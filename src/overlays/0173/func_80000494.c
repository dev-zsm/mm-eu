// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, M2C_UNK);        /* extern */
s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8398(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_8093E03C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8093E114(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_8093E190;

void func_80000494(u8 *arg0, M2C_UNK arg1) {
    func_80137070(arg0 + 0x190);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x16), 3, 0x400, 0x80);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    if (func_800B8254(arg0, arg1) != 0) {
        func_8093E114(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_8093E190;
    } else if ((M2C_FIELD(arg0, f32 *, 0x98) < 120.0f) && (func_800B70A4(arg0, 0x3000, arg1) != 0)) {
        func_800B8398(arg0, arg1, 0x43020000);
    }
    func_8093E03C(arg0, arg1);
}
