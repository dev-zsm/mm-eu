// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490();                            /* extern */
extern s32 D_80992550;
extern f32 D_80992560;

void func_800002AC(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x174) < D_80992560) {
        D_80992550 = 0;
        func_800B6490();
    }
}
