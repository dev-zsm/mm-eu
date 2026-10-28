// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80B7085C(u8 *, s32);                 /* extern */
M2C_UNK func_80B70CE8(u8 *);                      /* extern */

void func_80000DE0(u8 *arg0, s32 arg1) {
    u8 temp_v0;

    func_80137070(arg0 + 0x194);
    func_80B7085C(arg0, arg1);
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x300);
    if ((s32) temp_v0 > 0) {
        M2C_FIELD(arg0, u8 *, 0x300) = (u8) (temp_v0 - 1);
        return;
    }
    func_80B70CE8(arg0);
    M2C_FIELD(arg0, s8 *, 0x301) = 0;
    func_800E2500(arg1, arg1 + 0x18884, arg0 + 0x148);
    M2C_FIELD(arg0, u16 *, 0x2F8) = (u16) (M2C_FIELD(arg0, u16 *, 0x2F8) & 0xFFFD);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
}
