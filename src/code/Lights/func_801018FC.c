// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Lights_PointSetPosition(struct LightInfo *info, s16 x, s16 y, s16 z) {
    M2C_FIELD(info, s16 *, 2) = x;
    M2C_FIELD(info, s16 *, 4) = y;
    M2C_FIELD(info, s16 *, 6) = z;
}
