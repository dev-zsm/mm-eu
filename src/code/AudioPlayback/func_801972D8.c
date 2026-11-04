// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x30];
} AudioList;

extern void *AudioList_PopBack();
extern void AudioPlayback_NoteInitForLayer(void *note, void *layer);
extern void AudioList_PushFront(AudioList *list, void *item);

void *AudioPlayback_AllocNoteFromDisabled(AudioList *pool, void *layer) {
    void *note = AudioList_PopBack();

    if (note != NULL) {
        AudioPlayback_NoteInitForLayer(note, layer);
        AudioList_PushFront(pool + 1, note);
    }
    return note;
}
