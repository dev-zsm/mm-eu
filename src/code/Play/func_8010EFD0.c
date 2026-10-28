// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x266];
    s16 v266;
    s16 v268;
    s16 v26A;
    s16 v26C;
    s16 v26E;
} Blk;

extern u8 D_801EAE0E;
extern void func_8010EE98(void *a, s16 b);

void func_8010EFD0(u8 *play, s16 a1, s16 a2) {
    Blk *b = (Blk *)(play + 0x169E8);

    if (D_801EAE0E != 0) {
        func_8010EE98(play, a2);
        return;
    }
    if (b->v268 != 0 && a1 < b->v268) {
        b->v268 = a1;
    }
    if (b->v266 != 0 && a1 < b->v266) {
        b->v266 = a1;
    }
    if (b->v26A != 0 && a1 < b->v26A) {
        b->v26A = a1;
    }
    if (b->v26C != 0 && a1 < b->v26C) {
        b->v26C = a1;
    }
    if (b->v26E != 0 && a1 < b->v26E) {
        b->v26E = a1;
    }
}
