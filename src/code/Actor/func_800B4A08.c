// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Matrix_MultVec3f(s32, s32);                    /* extern */

void Actor_SetFeetPos(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (arg1 == arg2) {
        Matrix_MultVec3f(arg3, arg0 + 0xD4);
        return;
    }
    if (arg1 == arg4) {
        Matrix_MultVec3f(arg5, arg0 + 0xE0);
    }
}
