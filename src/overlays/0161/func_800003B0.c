#include "types.h"
typedef struct { u8 pad0[0x14]; s16 a14; } Q;
typedef struct { u8 pad0[0xA74]; u32 a74; } R;
typedef struct { u8 pad0[0x250]; Q* q; } P;
typedef struct { u8 pad0[0x1CCC]; R* r; } S;
s32 func_800003B0(P *a, S *play) {
    R *pl = play->r;
    if (a->q->a14 >= 0x14) {
        return 0;
    }
    if (pl->a74 & 0x20000000) {
        return 0;
    }
    return 1;
}
