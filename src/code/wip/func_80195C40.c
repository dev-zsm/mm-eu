// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad0; u8 f; u8 pad2[10]; u16 rate; } Note;
extern f32 D_801D7D78;
extern f32 D_801D7D7C;
extern f32 D_801D7D80;
void AudioPlayback_NoteSetResamplingRate(Note *n, f32 r) {
    f32 v;
    if (r < 2.0f) {
        n->f &= ~2;
        if (D_801D7D78 < r) {
            v = D_801D7D78;
        } else {
            v = r;
        }
    } else {
        n->f |= 2;
        if (D_801D7D7C < r) {
            v = D_801D7D80;
        } else {
            v = r * 0.5f;
        }
    }
    n->rate = (s32)(v * 32768.0f);
}
