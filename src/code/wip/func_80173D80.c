#include "types.h"

extern u8 D_801D7500[7];

extern void AudioSfx_StopByBank(u8 arg0);

// Remaining diff: the ROM compares through t6 and reloads *p into a0 in the jal delay slot; we reuse a0.
void AudioMgr_StopAllSfxExceptSystem(void) {
    u8 *p;

    for (p = D_801D7500; p < D_801D7500 + 7; p++) {
        if (*p != 4) {
            AudioSfx_StopByBank(*p);
        }
    }
}
