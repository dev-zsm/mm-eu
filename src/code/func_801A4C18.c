// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_PlaySfx_AtPosWithAllChannelsIO(M2C_UNK *, M2C_UNK, s32);     /* extern */
extern s8 D_801CEFD8;
extern M2C_UNK D_801D3DD4;

void Audio_PlaySfx_SurroundSoundTest(void) {
    s32 var_v0;

    var_v0 = 0;
    if (D_801CEFD8 == 2) {
        var_v0 = 2;
    }
    Audio_PlaySfx_AtPosWithAllChannelsIO(&D_801D3DD4, 0x484B, var_v0 & 0xFF);
}
