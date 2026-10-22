// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Collider_SetElementDamageInfoAC(s32 arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(arg2, s32 *, 0);
    M2C_FIELD(arg1, u8 *, 4) = (u8) M2C_FIELD(arg2, u8 *, 4);
    M2C_FIELD(arg1, u8 *, 5) = (u8) M2C_FIELD(arg2, u8 *, 5);
    return 1;
}
