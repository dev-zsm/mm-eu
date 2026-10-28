// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8);                          /* extern */
s32 func_800F1984(s8);                              /* extern */
M2C_UNK func_800F1A08(s8, s32);                     /* extern */
M2C_UNK func_800F1D6C(s8);                          /* extern */
extern M2C_UNK D_80B16F00;

void func_80000C98(u8 *arg0, u8 *arg1) {
    s32 pad;
    u8 *sp20;
    s16 temp_v0;

    sp20 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (func_800F1984(M2C_FIELD(arg0, s8 *, 0x38)) != 0) {
        func_800F1A08(M2C_FIELD(arg0, s8 *, 0x38), M2C_FIELD(arg0, s32 *, 0x1DC));
        M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80B16F00;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1E8);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x1E8) = (s16) (temp_v0 - 1);
    } else if (temp_v0 == 0) {
        func_800F1D6C(M2C_FIELD(sp20, s8 *, 0xA86));
        M2C_FIELD(sp20, s8 *, 0xA86) = -1;
        M2C_FIELD(arg0, s16 *, 0x1E8) = -1;
    }
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
}
