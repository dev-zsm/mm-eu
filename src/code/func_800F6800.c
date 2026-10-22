// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern f32 D_801D59D0;
extern void *D_801EB7E0;

void Environment_UpdateSkyboxRotY(void *arg0) {
    u8 temp_v0;

    if ((M2C_FIELD(arg0, u16 *, 0x16F1C) == 0) && (M2C_FIELD(arg0, u16 *, 0x16F1E) == 0) && ((temp_v0 = M2C_FIELD(arg0, u8 *, 0x18874), (temp_v0 == 1)) || (temp_v0 == 3))) {
        M2C_FIELD(arg0, f32 *, 0x48EC) = (f32) (M2C_FIELD(arg0, f32 *, 0x48EC) - ((f32) M2C_FIELD(D_801EB7E0, s16 *, 0x32) * D_801D59D0));
    }
}
