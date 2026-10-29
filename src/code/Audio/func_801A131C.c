// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801CEFCF;
extern u8 D_801CEFD0;
extern s8 D_801CEFDC;
extern u8 D_801F4ACD;
extern u8 D_801F4ACE;
extern u8 D_801F4ACF;
extern u8 D_801F4AD0;
extern void Audio_SetGanonsTowerBgmVolume(u8);
extern void AudioSeq_SetVolumeScale(s32, s32, u8, s32);

void Audio_UpdateRiverSoundVolumes(void) {
    if (D_801F4ACF == 1) {
        if (D_801F4ACE != D_801F4ACD) {
            AudioSeq_SetVolumeScale(0, 0, D_801F4ACD, 0xA);
            D_801F4ACE = D_801F4ACD;
            D_801F4AD0 = 1;
        }
        D_801F4ACF = 0;
    } else if ((D_801F4AD0 == 1) && (D_801CEFDC == 0)) {
        AudioSeq_SetVolumeScale(0, 0, 0x7F, 0xA);
        D_801F4ACE = 0x7F;
        D_801F4AD0 = 0;
    }
    if (D_801CEFD0 != 0) {
        D_801CEFD0--;
        if (D_801CEFD0 == 0) {
            Audio_SetGanonsTowerBgmVolume(D_801CEFCF);
        }
    }
}
