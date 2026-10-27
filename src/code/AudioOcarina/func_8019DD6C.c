// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { s8 unk0; s8 unk1; s8 unk2; } St;
extern s8 AudioOcarina_MapPitchToButton(u8);
extern u8 D_801CF910;
extern u16 D_801CF928;
extern u8 D_801CF930;
extern u8 *D_801D0E20;
extern u8 D_801D0E6C[];
extern St D_801F4C7E;
void AudioOcarina_UpdatePlaybackStaff(void) {
    if ((D_801CF930 & 0x3F) < 0x10) {
        D_801F4C7E.unk0 = AudioOcarina_MapPitchToButton(D_801CF930);
    }
    D_801F4C7E.unk1 = D_801CF910;
    if (D_801D0E6C != D_801D0E20) {
        D_801F4C7E.unk2 = D_801CF928;
    } else if (D_801CF928 == 0) {
        D_801F4C7E.unk2 = 0;
    } else {
        D_801F4C7E.unk2 = ((D_801CF928 - 1) % 8) + 1;
    }
}
