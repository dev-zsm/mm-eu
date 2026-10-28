// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80AB61F8;
extern M2C_UNK D_80AB63D8;
extern M2C_UNK D_80AB6FF0;

void func_80000C1C(u8 *arg0, M2C_UNK arg1) {
    s32 sp1C;

    sp1C = func_800B5B20(arg1, 0, arg1, arg0);
    M2C_FIELD(arg0, s16 *, 0x1EE) = (s16) M2C_FIELD(arg0, s8 *, 0x38);
    func_800BD9E0(arg0 + 0x190, &D_80AB6FF0, 0, arg0);
    if (sp1C == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AB63D8;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AB61F8;
}
