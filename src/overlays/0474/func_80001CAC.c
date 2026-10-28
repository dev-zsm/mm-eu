// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16, u8 *);                 /* extern */
s32 func_800F1984(s16, u8 *);                     /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
extern M2C_UNK D_80B0EDC4;

void func_80001CAC(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x2B4) == 0) {
        if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x2BA), arg0) == 0) {
            func_800F1944(M2C_FIELD(arg0, s16 *, 0x2BA), arg0);
            return;
        }
        M2C_FIELD(arg0, s16 *, 0x2B4) = 0xF;
        func_800F1A08(M2C_FIELD(arg0, s16 *, 0x2BA), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80B0EDC4;
    }
}
