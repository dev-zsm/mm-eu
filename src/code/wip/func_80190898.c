// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 numEntries;
    u8 pad4[0x1A];
    s16 unk1E;
} FontTbl;

extern s16 D_801FB102;
extern s16 D_801FB10E;
extern FontTbl D_801FB010;
void AudioHeap_DiscardFont(s32);

void AudioLoad_DiscardFont(s32 arg0) {
    u32 i;
    FontTbl *p;
    FontTbl *t;

    if (D_801FB102 == arg0) {
        D_801FB102 = -1;
    } else if (D_801FB10E == arg0) {
        D_801FB10E = -1;
    }
    t = &D_801FB010;
    i = 0;
    if (t->numEntries != 0) {
        p = t;
        do {
            if (arg0 == p->unk1E) {
                p->unk1E = -1;
            }
            i++;
            p = (FontTbl *)((u8 *)p + 0xC);
        } while (i < t->numEntries);
    }
    AudioHeap_DiscardFont(arg0);
}
