// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801D176C;
extern void AudioVoice_InitWordImpl(void);

void AudioVoice_InitWord(u16 arg0) {
    if (D_801D176C != 0) {
        if (arg0 < 6) {
            AudioVoice_InitWordImpl();
        }
    }
}
