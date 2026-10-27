// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
} Inner;

typedef struct {
    u8 pad0[0x60];
    Inner *unk60;
} Src;

typedef struct {
    u8 pad0[0x34];
    u8 unk34;
    u8 pad35[0x44 - 0x35];
    Src *unk44;
    u8 pad48[0x68 - 0x48];
    u8 unk68;
    u8 pad69[0x74 - 0x69];
    f32 unk74;
} Note;

extern f32 D_801FAD38;

void AudioPlayback_NoteReleaseAndTakeOwnership(Note *arg0, Src *arg1) {
    arg0->unk44 = arg1;
    arg0->unk34 = arg1->unk60->unk5;
    arg0->unk74 = D_801FAD38;
    // the redundant re-read of arg1->unk60->unk5 in an empty if is needed to match
    if ((!arg1->unk60->unk5) && (!arg1->unk60->unk5)) {
    }
    arg0->unk68 |= 0x10;
}
