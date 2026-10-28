// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFBF8(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80137C58(s32, s32);                        /* extern */
M2C_UNK func_809794F0(M2C_UNK, u8 *, u8 *);     /* extern */
M2C_UNK func_8097A770(u8 *);                      /* extern */

void func_80001068(u8 *arg0, M2C_UNK arg1) {
    s32 var_s0;

    func_800FFBF8(arg0 + 0xCC, 0x41C80000, 0x3F800000, 0x40200000);
    func_800FFCBC(arg0 + 0xBC, 0, 0x10, 0x7D0, 0x64);
    if (func_80137C58(arg0 + 0x144, M2C_FIELD(arg0, s32 *, 0x154)) != 0) {
        M2C_FIELD(arg0, s16 *, 0xBC) = 0;
        M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
        func_8097A770(arg0);
    }
    var_s0 = 0;
    if (M2C_FIELD(arg0, u16 *, 0x90) & 2) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        do {
            func_809794F0(arg1, arg0, arg0 + 0x24);
            var_s0 += 1;
        } while (var_s0 != 0xA);
    }
}
