// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(M2C_UNK, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_8013CD14(u8 *, M2C_UNK, s32, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80932AE8(u8 *, M2C_UNK);             /* extern */
s32 func_80932BE8(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80932CCC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80932DC0(u8 *);                      /* extern */
s32 func_80933974(u8 *, M2C_UNK);                 /* extern */
s32 func_80933AB4(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80933DD8(u8 *);                      /* extern */
M2C_UNK func_8093402C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80935A1C(u8 *, M2C_UNK);             /* extern */

void func_80003384(u8 *arg0, M2C_UNK arg1) {
    u8 temp_v1;

    if (func_80932BE8(arg0, arg1) == 0) {
        if ((func_80933974(arg0, arg1) == 0) && (func_80933AB4(arg0, arg1) != 0)) {
            func_80935A1C(arg0, arg1);
            func_80932AE8(arg0, arg1);
            func_80932DC0(arg0);
            return;
        }
        M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
        func_8093402C(arg0, arg1);
        if (M2C_FIELD(arg0, u8 *, 0x258) != 0) {
            func_80932AE8(arg0, arg1);
            func_80932DC0(arg0);
            func_80933DD8(arg0);
            func_8013CD14(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x3B4), 0x41F00000, 0, M2C_FIELD(arg0, u16 *, 0x3A4) & 7);
            temp_v1 = M2C_FIELD(arg0, u8 *, 0x258);
            if ((temp_v1 != 3) && (temp_v1 != 5) && (temp_v1 != 8)) {
                func_800B680C(arg0);
                func_800B763C(arg1, arg0, 0x41F00000, 0x41400000, 0.0f, 4);
            }
            func_80932CCC(arg0, arg1);
        }
    }
}
