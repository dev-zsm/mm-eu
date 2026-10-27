// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(s32);                             /* extern */
M2C_UNK Scene_ExecuteCommands(s32, s32);                    /* extern */
extern s32 D_801EAB9C;

void Scene_CommandAltHeaderList(s32 arg0, void *arg1) {
    s32 temp_a0;

    if (D_801EAB9C != 0) {
        temp_a0 = M2C_FIELD((func_80100304(M2C_FIELD(arg1, s32 *, 4)) + (D_801EAB9C * 4)), s32 *, -4);
        if (temp_a0 != 0) {
            Scene_ExecuteCommands(arg0, func_80100304(temp_a0));
            M2C_FIELD(arg1, s8 *, 8) = 0x14;
        }
    }
}
