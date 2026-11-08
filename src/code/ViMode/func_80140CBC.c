// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void ViMode_ConfigureFeatures(struct ViMode *viMode, s32 viFeatures) {
    s32 var_v0;

    var_v0 = M2C_FIELD(viMode, s32 *, 4);
    if (viFeatures & 1) {
        var_v0 |= 8;
    }
    if (viFeatures & 2) {
        var_v0 &= ~8;
    }
    if (viFeatures & 4) {
        var_v0 |= 4;
    }
    if (viFeatures & 8) {
        var_v0 &= ~4;
    }
    if (viFeatures & 0x10) {
        var_v0 |= 0x10;
    }
    if (viFeatures & 0x20) {
        var_v0 &= ~0x10;
    }
    M2C_FIELD(viMode, s32 *, 4) = var_v0;
}
