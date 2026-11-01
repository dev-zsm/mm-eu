// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_PlaySfx_AtPosWithFreq(M2C_UNK *, M2C_UNK, f32);     /* extern */
M2C_UNK Audio_PlaySfx_AtPosWithTimer(M2C_UNK *, M2C_UNK, f32);     /* extern */
extern M2C_UNK D_801D3DD4;
extern f32 D_801D8678;
extern f32 D_801D867C;

void Audio_PlaySfx_FishingReel(f32 arg0) {
    Audio_PlaySfx_AtPosWithTimer(&D_801D3DD4, 0x103D, arg0);
    Audio_PlaySfx_AtPosWithFreq(&D_801D3DD4, 0, (D_801D8678 * arg0) + D_801D867C);
}
