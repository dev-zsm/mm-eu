// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSfx_PlaySfx(u16, s32, M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK D_801D3DE0;
extern M2C_UNK D_801D3DE8;

void Audio_PlaySfx_AtPos(s32 arg0, u16 arg1) {
    AudioSfx_PlaySfx(arg1, arg0, 4, &D_801D3DE0, &D_801D3DE0, &D_801D3DE8);
}
