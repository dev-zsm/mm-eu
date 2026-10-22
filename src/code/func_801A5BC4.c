// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioOcarina_ResetStaffs();                            /* extern */
M2C_UNK AudioSfx_ResetSfxChannelState();                            /* extern */
M2C_UNK Audio_ResetData();                            /* extern */
M2C_UNK AudioSfx_Init(M2C_UNK);                     /* extern */
M2C_UNK func_801A68E0();                            /* extern */
M2C_UNK AudioSfx_Reset();                            /* extern */
M2C_UNK AudioSeq_ResetActiveSequencesAndVolume();                            /* extern */

void Audio_InitSound(void) {
    Audio_ResetData();
    AudioOcarina_ResetStaffs();
    AudioSfx_ResetSfxChannelState();
    AudioSeq_ResetActiveSequencesAndVolume();
    AudioSfx_Reset();
    func_801A68E0();
    AudioSfx_Init(0xA);
}
