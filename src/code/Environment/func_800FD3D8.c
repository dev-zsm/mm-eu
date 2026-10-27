// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Environment_LerpRGB8(s32, s32, s32, s32);          /* extern */

void Environment_LerpDiffuseColor(s32 arg0, s32 arg1, s32 arg2) {
    Environment_LerpRGB8(arg0 + 0x170CE, arg1, arg2, arg0 + 0x17096);
    Environment_LerpRGB8(arg0 + 0x170D4, arg1, arg2, arg0 + 0x1709C);
}
