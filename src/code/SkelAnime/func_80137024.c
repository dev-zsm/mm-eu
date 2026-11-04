#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 mode;
    u8 pad2[0x2E];
    void (*update)();
} SkelAnime;

extern void SkelAnime_LoopFull();
extern void SkelAnime_LoopPartial();
extern void SkelAnime_Once();

void SkelAnime_SetUpdate(SkelAnime *skelAnime) {
    if (skelAnime->mode < 2) {
        skelAnime->update = SkelAnime_LoopFull;
    } else if (skelAnime->mode < 4) {
        skelAnime->update = SkelAnime_Once;
    } else {
        skelAnime->update = SkelAnime_LoopPartial;
    }
}
