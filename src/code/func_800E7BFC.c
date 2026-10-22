// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Collider_SetCylinderPosition(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s16 *, 0x46) = (s16) M2C_FIELD(arg1, s16 *, 0);
    M2C_FIELD(arg0, s16 *, 0x48) = (s16) M2C_FIELD(arg1, s16 *, 2);
    M2C_FIELD(arg0, s16 *, 0x4A) = (s16) M2C_FIELD(arg1, s16 *, 4);
}
