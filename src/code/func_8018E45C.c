// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    void *ptr;
    u8 pad4[4];
    s16 tableType;
    s16 id;
} PermanentEntry;

typedef struct {
    u8 pad0[0x2D90];
    PermanentEntry entries[1];
} AudioContext;

extern AudioContext D_801F84B0;
extern s32 D_801FB23C;

void *AudioHeap_SearchPermanentCache(s32 tableType, s32 id) {
    s32 i;

    for (i = 0; i < D_801FB23C; i++) {
        if (D_801F84B0.entries[i].tableType == tableType && D_801F84B0.entries[i].id == id) {
            return D_801F84B0.entries[i].ptr;
        }
    }
    return NULL;
}
