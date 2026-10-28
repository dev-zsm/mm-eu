// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808A0010(u8 *, M2C_UNK *);           /* extern */
s32 func_808A0094(u8 *, u8 *);                  /* extern */
s32 func_808A0A60(u8 *);                          /* extern */
extern M2C_UNK D_808A1268;

void func_80000D94(u8 *arg0, u8 *arg1) {
    f32 var_f0;
    s8 temp_v0;
    s8 var_v1;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0x166);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s8 *, 0x166) = (s8) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s8 *, 0x166);
    }
    if ((var_v1 == 0) && (M2C_FIELD(arg1, s8 *, 0x18711) == 0) && (func_808A0A60(arg0) != 0)) {
        if (M2C_FIELD(arg0, u8 *, 0x162) == 5) {
            var_f0 = 20.0f;
        } else {
            var_f0 = 50.0f;
        }
        if (var_f0 < M2C_FIELD(arg0, f32 *, 0x98)) {
            if (M2C_FIELD(arg0, u8 *, 0x163) == 7) {
                M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
            } else {
                if (func_808A0094(arg0, arg1) != 0) {
                    M2C_FIELD(arg0, f32 *, 0x68) = 30.0f;
                }
                func_800B8C4C(arg0, 0x281C);
            }
            func_808A0010(arg0, &D_808A1268);
        }
    }
}
