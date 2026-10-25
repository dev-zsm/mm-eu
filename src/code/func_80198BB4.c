#include "types.h"

extern void AudioScript_SequencePlayerDisable(u8* seqPlayer);

void AudioScript_SequencePlayerDisableAsFinished(u8* seqPlayer) {
    u8* seq = seqPlayer; // extra copy needed for the scheduling to match

    seqPlayer[0] = (seqPlayer[0] & 0xFF) | 0x40;
    AudioScript_SequencePlayerDisable(seq);
}
