// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6308(s32, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_80AD0C90;
extern s32 D_80AD0C94;

void func_80000000(u8 *arg0, s32 arg1) {
    if (D_80AD0C94 == 0) {
        func_800B6308(arg1, 0x1D2, &D_80AD0C90, 2);
        D_80AD0C94 = 1;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x1EC) = &D_80AD0C90;
}
