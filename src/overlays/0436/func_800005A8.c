// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_80ACED74;
extern M2C_UNK D_80ACEED0;
extern M2C_UNK D_80AD0A80;

void func_800005A8(u8 *arg0) {
    if (&D_80ACEED0 == M2C_FIELD(arg0, M2C_UNK **, 0x1D4)) {
        func_800BD9E0(arg0 + 0x190, &D_80AD0A80, 0x11);
    } else {
        func_800BD9E0(arg0 + 0x190, &D_80AD0A80, 3);
    }
    func_800B8C4C(arg0, 0x3987);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80ACED74;
}
