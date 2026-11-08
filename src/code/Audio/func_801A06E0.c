// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSfx_PlaySfx(s32, s32, M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK D_801CEF78;
extern M2C_UNK D_801CEF7C;
extern M2C_UNK D_801D3DE0;

void Audio_PlaySfx_GiantsMask(struct Vec3f *pos, u16 sfxId) {
    AudioSfx_PlaySfx(((sfxId & 0x681F) + 0x20) & 0xFFFF, pos, 4, &D_801CEF78, &D_801D3DE0, &D_801CEF7C);
}
