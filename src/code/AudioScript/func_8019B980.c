// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 padDC[0xDC];
    s32 skipTicks;
} SequencePlayer;

extern void AudioScript_SequencePlayerProcessSequence(SequencePlayer *seqPlayer);
extern void AudioScript_SequencePlayerProcessSound(SequencePlayer *seqPlayer);

void AudioScript_SkipForwardSequence(SequencePlayer *seqPlayer) {
    while (seqPlayer->skipTicks > 0) {
        AudioScript_SequencePlayerProcessSequence(seqPlayer);
        AudioScript_SequencePlayerProcessSound(seqPlayer);
        seqPlayer->skipTicks--;
    }
}
