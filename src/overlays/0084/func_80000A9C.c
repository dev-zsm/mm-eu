// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800B6A58(u8 *, s32);                     /* extern */
M2C_UNK func_808A30A0(u8 *);                      /* extern */
M2C_UNK func_808A3164(u8 *);                      /* extern */
M2C_UNK func_808A3224(u8 *, s32);                 /* extern */
M2C_UNK func_808A325C(u8 *);                      /* extern */

void func_80000A9C(u8 *arg0, M2C_UNK arg1) {
    s32 temp_a1;
    u8 *temp_v1;

    func_808A3164(arg0);
    temp_v1 = M2C_FIELD(arg0, u8 **, 0x2AC);
    if (temp_v1 != NULL) {
        temp_a1 = M2C_FIELD(temp_v1, s32 *, 0x2AC);
        if (temp_a1 != 0) {
            M2C_FIELD(arg0, s16 *, 0x16) = func_800B6A58(arg0, temp_a1);
            func_808A325C(arg0);
        } else {
            func_808A3224(arg0, temp_a1);
        }
        if ((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) == M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x2AC), s16 *, 0x18)) {
            func_808A30A0(arg0);
            M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x2AC), s16 *, 0x18) = 0;
        }
    }
}
