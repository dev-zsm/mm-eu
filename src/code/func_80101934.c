// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Lights_DirectionalSetInfo(void *arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6) {
    M2C_FIELD(arg0, s8 *, 0) = 1;
    M2C_FIELD(arg0, s8 *, 2) = arg1;
    M2C_FIELD(arg0, s8 *, 3) = arg2;
    M2C_FIELD(arg0, s8 *, 4) = arg3;
    M2C_FIELD(arg0, u8 *, 5) = arg4;
    M2C_FIELD(arg0, u8 *, 6) = arg5;
    M2C_FIELD(arg0, u8 *, 7) = arg6;
}
