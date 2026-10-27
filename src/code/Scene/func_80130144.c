// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(s32);                             /* extern */
M2C_UNK LightContext_InsertLight(s32, s32, s32);               /* extern */

void Scene_CommandLightList(s32 arg0, void *arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = func_80100304(M2C_FIELD(arg1, s32 *, 4));
    var_s1 = 0;
    if ((s32) M2C_FIELD(arg1, u8 *, 1) > 0) {
        do {
            LightContext_InsertLight(arg0, arg0 + 0x818, var_s0);
            var_s1 += 1;
            var_s0 += 0xE;
        } while (var_s1 < (s32) M2C_FIELD(arg1, u8 *, 1));
    }
}
