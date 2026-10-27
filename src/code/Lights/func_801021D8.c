#include "types.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Slot; /* size 0xC */

typedef struct {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 cur;
    /* 0x08 */ Slot slots[32];
} Buf;

extern Buf D_801EC7F0;

Slot *Lights_FindBufSlot(void) {
    Slot *s;

    if (D_801EC7F0.count >= 0x20) {
        return 0;
    }
    s = &D_801EC7F0.slots[D_801EC7F0.cur];
    while (s->a != 0) {
        D_801EC7F0.cur++;
        if (D_801EC7F0.cur < 0x20) {
            s++;
        } else {
            D_801EC7F0.cur = 0;
            s = D_801EC7F0.slots;
        }
    }
    D_801EC7F0.count++;
    return s;
}
