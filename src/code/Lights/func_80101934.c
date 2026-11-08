// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Lights_DirectionalSetInfo(struct LightInfo *info, s8 x, s8 y, s8 z, u8 r, u8 g, u8 b) {
    M2C_FIELD(info, s8 *, 0) = 1;
    M2C_FIELD(info, s8 *, 2) = x;
    M2C_FIELD(info, s8 *, 3) = y;
    M2C_FIELD(info, s8 *, 4) = z;
    M2C_FIELD(info, u8 *, 5) = r;
    M2C_FIELD(info, u8 *, 6) = g;
    M2C_FIELD(info, u8 *, 7) = b;
}
