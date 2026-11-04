// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct NoteList {
    u8 pad0[0xC];
    struct NoteList *owner;
} NoteList;

extern void AudioList_InitNoteList(NoteList *list);

void AudioList_InitNoteLists(NoteList *lists) {
    AudioList_InitNoteList(&lists[0]);
    AudioList_InitNoteList(&lists[1]);
    AudioList_InitNoteList(&lists[2]);
    AudioList_InitNoteList(&lists[3]);
    lists[0].owner = lists;
    lists[1].owner = lists;
    lists[2].owner = lists;
    lists[3].owner = lists;
}
