// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80A2AE04(u8 *);                      /* extern */
M2C_UNK func_80A2BB3C(u8 *);                      /* extern */

void func_80001964(u8 *arg0, M2C_UNK arg1) {
    f32 sp34;
    s32 var_s0;
    u8 *var_s1;

    sp34 = M2C_FIELD(arg0, f32 *, 0x15C);
    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 0xC8, 0x1F40, 0x1388);
    if (M2C_FIELD(arg0, s16 *, 0x3B6) >= 3) {
        func_80A2AE04(arg0);
    } else {
        var_s0 = 0;
        var_s1 = arg0 + 0x896;
        if (M2C_FIELD(arg0, s32 *, 0x740) > 0) {
            do {
                func_800FFCBC(var_s1, M2C_FIELD(arg0, s16 *, 0x92), 0xC8, 0x1F40, 0x1388);
                var_s0 += 1;
                var_s1 += 6;
            } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x740));
        }
    }
    if (M2C_FIELD(arg0, f32 *, 0x3D0) <= sp34) {
        M2C_FIELD(arg0, s16 *, 0x44C) = (s16) (M2C_FIELD(arg0, s16 *, 0x44C) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x44C) >= 2) {
            func_80A2BB3C(arg0);
        }
    }
    func_800FFCBC(arg0 + 0x3C4, M2C_FIELD(arg0, s16 *, 0x3C6), 0xA, 0xA, 0xA);
}
