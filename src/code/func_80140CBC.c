// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void ViMode_ConfigureFeatures(void *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = M2C_FIELD(arg0, s32 *, 4);
    if (arg1 & 1) {
        var_v0 |= 8;
    }
    if (arg1 & 2) {
        var_v0 &= ~8;
    }
    if (arg1 & 4) {
        var_v0 |= 4;
    }
    if (arg1 & 8) {
        var_v0 &= ~4;
    }
    if (arg1 & 0x10) {
        var_v0 |= 0x10;
    }
    if (arg1 & 0x20) {
        var_v0 &= ~0x10;
    }
    M2C_FIELD(arg0, s32 *, 4) = var_v0;
}
