// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void AudioPlayback_SeqLayerDecayRelease();
void AudioPlayback_SeqLayerNoteDecay(s32 a0) { AudioPlayback_SeqLayerDecayRelease(a0, 6); }
