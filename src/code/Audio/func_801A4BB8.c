// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void Audio_SetSfxReverbIndexExceptOcarinaBank(u8 a0, s8 a1);
extern s8 D_801CEFEC;

void Audio_SetCodeReverb(s8 reverb) {
    if (reverb != 0) {
        if ((reverb & 0x40) != (D_801CEFEC & 0x40)) {
            Audio_SetSfxReverbIndexExceptOcarinaBank((reverb >> 6) + 1, reverb);
        }
        D_801CEFEC = reverb & 0x7F;
    }
}
