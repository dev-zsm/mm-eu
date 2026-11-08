// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSfx_PlaySfx(u16, s32, M2C_UNK, M2C_UNK *, M2C_UNK *, s8 *); /* extern */
extern M2C_UNK D_801D3DE0;
extern s8 D_801F4ACC;

void Audio_PlaySfx_AtPosWithReverb(struct Vec3f *pos, u16 sfxId, s8 reverbAdd) {
    D_801F4ACC = reverbAdd;
    AudioSfx_PlaySfx(sfxId, pos, 4, &D_801D3DE0, &D_801D3DE0, &D_801F4ACC);
}
