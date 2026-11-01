#include "types.h"

extern u8 D_801D176C;
extern void AudioVoice_InitWordImplA(s32 arg0);

void AudioVoice_InitWordAlt(s32 arg0) {
    arg0 &= 0xFFFF;
    if ((D_801D176C != 0) && (arg0 < 6)) {
        AudioVoice_InitWordImplA(arg0);
    }
}
