// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80137070(u8 *);                          /* extern */
s32 func_8016A23C(s32);                             /* extern */
M2C_UNK func_801A3D04(M2C_UNK);                     /* extern */
M2C_UNK func_808698C0(u8 *, s32);                 /* extern */
M2C_UNK func_8086BEE8(u8 *);                      /* extern */

void func_8000299C(u8 *arg0, s32 arg1) {
    func_808698C0(arg0, arg1);
    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 5, 0x400, 0x80);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    if ((func_80137070(arg0 + 0x144) != 0) && (func_8016A23C(arg1) == 0)) {
        if (M2C_FIELD(arg0, u8 *, 0x2AE) == 0) {
            func_801A3D04(0x38);
            M2C_FIELD(arg0, u8 *, 0x2AE) = 1U;
        }
        func_8086BEE8(arg0);
    }
}
