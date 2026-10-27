// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioOcarina_PlayControllerInput(M2C_UNK);                     /* extern */
M2C_UNK Audio_SetSfxVolumeExceptSystemAndOcarinaBanks(M2C_UNK);                     /* extern */
M2C_UNK func_801A6A90(M2C_UNK);                     /* extern */
M2C_UNK AudioSfx_RestoreBgmVolume(M2C_UNK);                     /* extern */
M2C_UNK AudioSfx_StopById(M2C_UNK);                     /* extern */
extern s8 D_801CF8E4;
extern s8 D_801CF910;
extern s32 D_801CF91C;
extern s16 D_801CF928;
extern u8 D_801D3E04;
extern s32 D_801F4C90;
extern s32 D_801F4C94;
extern s32 D_801F4C98;
extern s32 D_801F4C9C;

void AudioOcarina_ResetAndMute(void) {
    D_801F4C90 = 0;
    D_801F4C98 = 0;
    D_801F4C9C = 0;
    D_801F4C94 = 0xFFFF;
    AudioOcarina_PlayControllerInput(0);
    AudioSfx_StopById(0x5800);
    if (D_801D3E04 != 0xC) {
        func_801A6A90(0);
    }
    D_801CF910 = 0;
    D_801CF928 = 0;
    D_801CF8E4 = 0;
    D_801CF91C = 0;
    AudioSfx_RestoreBgmVolume(0xD);
    Audio_SetSfxVolumeExceptSystemAndOcarinaBanks(0x7F);
}
