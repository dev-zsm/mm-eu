#include "types.h"
#include "m2c_compat.h"

extern s32 D_801EFA18;

void func_80000000(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s8 var_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2E0);
    if (((temp_v0 >= 0) && (temp_v0 < 6)) || (temp_v0 == 0x20) || (temp_v0 == 0x21) || (temp_v0 == 0x28) || (temp_v0 == 0x29)) {
        var_v0 = M2C_FIELD(arg0, s8 *, 0x336);
    } else if (temp_v0 >= 0x41) {
        var_v0 = M2C_FIELD(arg0, s8 *, 0x338);
    } else {
        var_v0 = M2C_FIELD(arg0, s8 *, 0x337);
    }
    if (var_v0 >= 0) {
        D_801EFA18 = M2C_FIELD(((u8 *)((s32)arg1 + (var_v0 * 0x44))), s32 *, 0x17D98) + 0x80000000;
    }
}
