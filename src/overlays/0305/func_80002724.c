// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8, u8 *);                  /* extern */
s32 func_800F1984(s8, u8 *);                      /* extern */
M2C_UNK func_800F1A08(s8, u8 *);                  /* extern */
M2C_UNK func_80A0A554(u8 *);                      /* extern */
extern M2C_UNK D_80A0B928;

void func_80002724(u8 *arg0, M2C_UNK arg1) {
    if (func_800F1984(M2C_FIELD(arg0, s8 *, 0x38), arg0) != 0) {
        func_800F1A08(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x1AC) = &D_80A0B928;
        M2C_FIELD(arg0, s8 *, 0x2B1) = 0x50;
        func_80A0A554(arg0);
        return;
    }
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38), arg0);
}
