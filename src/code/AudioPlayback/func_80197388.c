// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
} Sub;

typedef struct Note {
    u8 pad0[0x34];
    u8 unk34;
    u8 pad35[0xF];
    struct Note *unk44;
} Note;

typedef struct {
    u8 pad0[0x60];
    Sub *unk60;
} Arg1;

extern Note *AudioList_FindNodeWithPrioLessThan();
extern void AudioList_Remove();
extern void func_80197278();
extern void AudioList_PushBack();

Note *AudioPlayback_AllocNoteFromActive(u8 *a0, Arg1 *a1) {
    Note *v1;
    Note *s0;
    s32 sp2C;
    s32 sp28;

    sp2C = sp28 = 0x10;
    v1 = AudioList_FindNodeWithPrioLessThan(a0 + 0x20, a1->unk60->unk5);
    if (v1 != NULL) {
        sp2C = v1->unk34;
    }
    s0 = AudioList_FindNodeWithPrioLessThan(a0 + 0x30, a1->unk60->unk5);
    if (s0 != NULL) {
        sp28 = s0->unk34;
    }
    if (v1 == NULL && s0 == NULL) {
        return NULL;
    }
    if (sp28 < sp2C) {
        AudioList_Remove(s0);
        func_80197278(s0, a1);
        AudioList_PushBack(a0 + 0x20, s0);
        s0->unk34 = a1->unk60->unk5;
        return s0;
    }
    v1->unk44 = (Note *)a1;
    v1->unk34 = a1->unk60->unk5;
    return v1;
}
