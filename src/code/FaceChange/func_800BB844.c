#include "types.h"
typedef struct { s16 index; s16 timer; } Blink;
extern s16 Rand_S16Offset(s16, s16);

s32 FaceChange_UpdateBlinking(Blink *b, s16 base, s16 range, s16 thresh) {
    s32 t;
    s32 d;

    if (b->timer == 0) {
        t = 0;
    } else {
        b->timer--;
        t = b->timer;
    }
    if (t == 0) {
        b->timer = Rand_S16Offset(base, range);
    }
    d = b->timer - thresh;
    if (d > 0) {
        b->index = 0;
    } else if (d >= -1 || b->timer < 2) {
        b->index = 1;
    } else {
        b->index = 2;
    }
    return b->index;
}
