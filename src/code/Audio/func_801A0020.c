// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSfx_PlaySfx(u16, s32, M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK D_801D3DE0;
extern M2C_UNK D_801F4A94;
extern M2C_UNK D_801F4A98;

void Audio_PlaySfx_AtPosWithPresetLowFreqAndHighReverb(s32 arg0, u16 arg1) {
    AudioSfx_PlaySfx(arg1, arg0, 4, &D_801F4A94, &D_801D3DE0, &D_801F4A98);
}
