#include "types.h"

typedef struct { u8 pad[0x160]; } Seq;
extern s16 D_801FAD30;
extern Seq D_801F84B0[];
extern void AudioScript_SequencePlayerDisable(void *p);

void AudioHeap_DiscardSequence(s32 id) {
    s32 i = 0;
    Seq *s = D_801F84B0;
    while (i < D_801FAD30) {
        if ((*(u32 *)((u8 *)s + 0x4460) >> 31) && *((u8 *)s + 0x4464) == id) {
            AudioScript_SequencePlayerDisable((u8 *)s + 0x4460);
        }
        i++;
        s++;
    }
}
