// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u32 D_801FCBD0;
extern u8 D_801F74C0;
extern void AudioSfx_ChooseActiveSfx(u8 arg0);
extern void AudioSfx_PlayActiveSfx(u8 arg0);
extern void AudioSfx_StepBankLerp(u8 arg0);

void AudioSfx_ProcessActiveSfx(void) {
    u8 i;

    if (D_801FCBD0 >> 31) {
        D_801F74C0 = 0;
        for (i = 0; i < 7; i++) {
            AudioSfx_ChooseActiveSfx(i);
            AudioSfx_PlayActiveSfx(i);
            AudioSfx_StepBankLerp(i);
        }
    }
}
