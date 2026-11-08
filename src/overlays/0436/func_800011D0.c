// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0436.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
s32 func_80ACE87C(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK D_80ACF994;
extern M2C_UNK D_80AD03C8;
extern M2C_UNK D_80AD0A80;

void func_800011D0(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x354) = 0;
    if (&D_80AD03C8 != M2C_FIELD(thisx, M2C_UNK **, 0x1D4)) {
        if (func_80ACE87C(0, 0) != 0) {
            func_800B8C4C(thisx, 0x3987);
        }
        func_800BD9E0((u8 *)thisx + 0x190, &D_80AD0A80, 0x10);
    }
    M2C_FIELD(thisx, M2C_UNK **, 0x1D4) = &D_80ACF994;
}
