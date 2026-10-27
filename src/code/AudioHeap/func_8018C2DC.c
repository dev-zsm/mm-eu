// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 priority;
    u8 unk1;
    u8 unk2;
    u8 fontId;
    u8 pad4[0x30];
    struct {
        u8 b0 : 1;
        u8 b1 : 1;
        u8 b2 : 1;
        u8 b3 : 1;
        u8 rest : 4;
    } flags; /* 0x34 */
    u8 pad35[0xB];
    f32 releaseRate; /* 0x40 */
} NotePlaybackState;

typedef struct {
    u8 pad0[0x34];
    NotePlaybackState playbackState; /* 0x34 */
    u8 pad78[0xF8 - 0x78];
} Note;

typedef struct {
    u8 pad0[0x2888];
    f32 unk2888;
    u8 pad288C[0x28B8 - 0x288C];
    s32 numNotes; /* 0x28B8 */
    u8 pad28BC[0x445C - 0x28BC];
    Note *notes; /* 0x445C */
} AudioContext;

extern AudioContext D_801F84B0;

void AudioHeap_ReleaseNotesForFont(s32 fontId) {
    s32 i;

    for (i = 0; i < D_801F84B0.numNotes; i++) {
        Note *note = &D_801F84B0.notes[i];
        NotePlaybackState *state = &note->playbackState;

        if (fontId == state->fontId) {
            if (state->priority != 0) {
                state->priority = 1;
                state->releaseRate = D_801F84B0.unk2888;
                state->flags.b3 = 1;
            }
        }
    }
}
