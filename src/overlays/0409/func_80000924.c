// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_80151DF4(s32, s32, M2C_UNK);           /* extern */
extern u8 D_801E7E27;
extern M2C_UNK D_80AAF454;

void func_80000924(u8 *arg0, s32 arg1) {
    if (!(D_801E7E27 & 1) && !(D_801E7E27 & 2)) {
        func_800B701C(arg1, arg0, 7);
        func_80151DF4(arg1, (((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x1FE0) >> 5) + 0x1883) & 0xFFFF, 0);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80AAF454;
    }
}
