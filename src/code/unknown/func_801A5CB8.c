// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioOcarina_ResetStaffs();                            /* extern */
M2C_UNK AudioSfx_ResetSfxChannelState();                            /* extern */
M2C_UNK Audio_ResetData();                            /* extern */
M2C_UNK AudioVoice_ResetWord();                            /* extern */
M2C_UNK func_801A6A90(M2C_UNK);                     /* extern */
M2C_UNK AudioSfx_Reset();                            /* extern */
M2C_UNK AudioSeq_ResetActiveSequences();                            /* extern */
extern u8 D_801D3E04;
extern s8 D_801D3E08;

void func_801A5CB8(s32 arg0) {
    D_801D3E08 = 1;
    Audio_ResetData();
    AudioOcarina_ResetStaffs();
    AudioSfx_ResetSfxChannelState();
    AudioSeq_ResetActiveSequences();
    AudioSfx_Reset();
    AudioVoice_ResetWord();
    if (D_801D3E04 == 0xB) {
        func_801A6A90(0x6F);
    }
}
