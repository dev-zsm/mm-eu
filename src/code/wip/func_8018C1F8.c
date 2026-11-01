#include "types.h"
typedef struct { u8 b0; } Fl;
typedef struct { u8 unk0; u8 pad1[0x33]; u8 unk34; u8 pad35[2]; u8 unk37; u8 unk38; u8 pad39[0xF]; Fl *unk48; u8 pad4C[0xF8 - 0x4C]; } Note;
extern struct { u8 pad0[0x28B8]; s32 unk28B8; u8 pad28BC[0x445C - 0x28BC]; Note *unk445C; } D_801F84B0;
extern u8 D_801FFDE8[];
extern void AudioPlayback_NoteDisable(Note *);
extern void AudioList_Remove(Note *);
extern void AudioList_PushBack(void *, Note *);
void AudioHeap_DiscardFont(s32 fontId) {
    s32 i = 0;
    Note *n;
    if (D_801F84B0.unk28B8 > 0) {
        do {
            n = &D_801F84B0.unk445C[i];
            if (fontId == n->unk37) {
                if (n->unk38 == 0 && n->unk34 != 0) {
                    n->unk48->b0 &= 0xFF7F;
                    n->unk48->b0 |= 0x40;
                }
                AudioPlayback_NoteDisable(n);
                AudioList_Remove(n);
                AudioList_PushBack(D_801FFDE8, n);
            }
            i++;
        } while (i < D_801F84B0.unk28B8);
    }
}
