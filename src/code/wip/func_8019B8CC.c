// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 flag;
    u8 pad4[0x15C];
} Note;
typedef struct {
    u8 pad0[0x2878];
    s16 unk2878;
    u8 pad287A[6];
    s16 unk2880;
    u8 pad2882[0x36];
    u32 unk28B8;
    u8 pad28BC[0x4460 - 0x28BC];
    Note notes[2];
} Heap;

extern Heap D_801F84B0;
void AudioScript_SequencePlayerProcessSequence(void *);
void AudioScript_SequencePlayerProcessSound(void *);
void AudioPlayback_ProcessNotes(void);
void AudioScript_ProcessSequences(s32 arg0) {
    u32 i;

    *(u32 *)((u8 *)&D_801F84B0 + 0x7924) = (D_801F84B0.unk2878 - arg0 - 1) * D_801F84B0.unk28B8;
    i = 0;
    if (D_801F84B0.unk2880 != 0) {
        do {
            if ((D_801F84B0.notes[i].flag >> 31) == 1) {
                AudioScript_SequencePlayerProcessSequence(&D_801F84B0.notes[i]);
                AudioScript_SequencePlayerProcessSound(&D_801F84B0.notes[i]);
            }
            i++;
        } while (i < D_801F84B0.unk2880);
    }
    AudioPlayback_ProcessNotes();
}
