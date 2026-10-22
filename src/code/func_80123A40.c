// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80123A40(void *arg0, s32 arg1) {
    s32 temp_a2;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x1CCC);
    temp_a2 = M2C_FIELD(temp_v1, s32 *, 0xA6C);
    if ((temp_a2 & 0x800) && (arg1 == M2C_FIELD(temp_v1, s32 *, 0x34C))) {
        M2C_FIELD(temp_v1, s32 *, 0x388) = 0;
        M2C_FIELD(temp_v1, s32 *, 0x34C) = 0;
        M2C_FIELD(temp_v1, s32 *, 0x124) = 0;
        M2C_FIELD(temp_v1, s32 *, 0xA6C) = (s32) (temp_a2 & ~0x800);
        return 1;
    }
    return 0;
}
