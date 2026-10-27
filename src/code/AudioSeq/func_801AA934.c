// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct {
    u8 pad0[0x1C0];
    f32 unk1C0;
    u8 pad1[0x200 - 0x1C4];
    s16 unk200;
    u8 pad2[0x212 - 0x202];
    u8 unk212[4];
    u8 pad3;
    u8 unk217;
    u8 pad4[4];
} Ch;
extern Ch D_801F7980[5];
void AudioSeq_ResetActiveSequences(void);
void AudioSeq_ResetActiveSequencesAndVolume(void) {
    u8 i;
    u8 j;
    for (i = 0; i < 5; i++) {
        D_801F7980[i].unk1C0 = 1.0f;
        D_801F7980[i].unk200 = 0;
        D_801F7980[i].unk217 = 0;
        for (j = 0; j < 4; j++) {
            D_801F7980[i].unk212[j] = 0x7F;
        }
    }
    AudioSeq_ResetActiveSequences();
}
