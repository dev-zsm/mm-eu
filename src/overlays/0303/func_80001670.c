// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C60A4(s32, s32, s32);               /* extern */
s32 func_800CAD00(u8 *);                          /* extern */
s32 func_800FEE3C(u8 *, s32, M2C_UNK);            /* extern */
s32 func_80A05E80(u8 *);                          /* extern */
M2C_UNK func_80A069E4(u8 *, s32);                 /* extern */
M2C_UNK func_80A07038(u8 *);                      /* extern */
extern M2C_UNK D_80A07608;
extern s32 D_80A07740;

void func_80001670(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    if (func_80A05E80(arg0) != -1) {
        func_80A069E4(arg0, arg1);
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x17A);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x17A) = (s16) (temp_v0 - 1);
        return;
    }
    func_800C60A4(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144));
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A07608;
    if (func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0xC), 0x3F800000) != 0) {
        func_80A07038(arg0);
    }
    if (func_800CAD00(arg0) != 0) {
        D_80A07740 |= 1 << M2C_FIELD(arg0, u8 *, 0x1C0);
    }
}
