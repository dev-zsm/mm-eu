// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void EffectTireMark_InitElement(void *arg0) {
    s16 temp_v0;

    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    temp_v0 = M2C_FIELD(arg0, s16 *, 0xC);
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = temp_v0;
    M2C_FIELD(arg0, s16 *, 8) = temp_v0;
    M2C_FIELD(arg0, s16 *, 6) = temp_v0;
    M2C_FIELD(arg0, s16 *, 4) = temp_v0;
    M2C_FIELD(arg0, s16 *, 2) = temp_v0;
}
