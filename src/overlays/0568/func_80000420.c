// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_80BB43D4;
extern M2C_UNK D_80BB4DA8;

void func_80000420(u8 *arg0) {
    func_800BD9E0(arg0 + 0x190, &D_80BB4DA8, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80BB43D4;
}
