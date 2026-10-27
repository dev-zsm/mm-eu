// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern s16 D_801C00A0;
extern s16 D_801C00A4;
extern s16 D_801C00A8;

void Map_SetAreaEntrypoint(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x1CCC);
    D_801C00A0 = (s16) (s32) M2C_FIELD(temp_v0, f32 *, 0x24);
    D_801C00A4 = (s16) (s32) M2C_FIELD(temp_v0, f32 *, 0x2C);
    D_801C00A8 = (s16) ((s32) (0x7FFF - M2C_FIELD(temp_v0, s16 *, 0xBE)) / 1024);
}
