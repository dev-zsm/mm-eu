// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16, u8 *);                 /* extern */
s32 func_800F1984(s16, u8 *);                     /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
M2C_UNK func_80B2BBF0(u8 *);                      /* extern */
extern s16 D_80B35134;

void func_80003494(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2F0);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2F0) = (s16) (temp_v0 - 1);
        return;
    }
    if (func_800F1984(D_80B35134, arg0) != 0) {
        func_800F1A08(D_80B35134, arg0);
        func_80B2BBF0(arg0);
        return;
    }
    func_800F1944(D_80B35134, arg0);
}
