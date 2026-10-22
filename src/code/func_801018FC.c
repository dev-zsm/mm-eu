// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Lights_PointSetPosition(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 2) = arg1;
    M2C_FIELD(arg0, s16 *, 4) = arg2;
    M2C_FIELD(arg0, s16 *, 6) = arg3;
}
