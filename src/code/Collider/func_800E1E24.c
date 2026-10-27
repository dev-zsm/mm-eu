// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_ResetOCBase(s32, s32);                    /* extern */
M2C_UNK Collider_ResetOCElement(s32, s32);                    /* extern */

s32 Collider_ResetQuadOC(s32 arg0, s32 arg1) {
    Collider_ResetOCBase(arg0, arg1);
    Collider_ResetOCElement(arg0, arg1 + 0x18);
    return 1;
}
