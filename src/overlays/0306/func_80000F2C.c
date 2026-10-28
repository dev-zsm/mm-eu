// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800B6A58(u8 *, u8 *);                  /* extern */
M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A0DB70(u8 *, u8 *);              /* extern */

void func_80000F2C(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v1;
    u8 *temp_a1;

    func_80137070(arg0 + 0x144);
    temp_a1 = M2C_FIELD(arg0, u8 **, 0x120);
    temp_v1 = M2C_FIELD(temp_a1, s16 *, 0x1C);
    if (temp_v1 == 7) {
        func_800FEC70(arg0 + 0xBE, func_800B6A58(arg0, temp_a1), 0x400);
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        return;
    }
    if (temp_v1 == 8) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        return;
    }
    if (temp_v1 == 3) {
        func_80A0DB70(arg0, temp_a1);
    }
}
