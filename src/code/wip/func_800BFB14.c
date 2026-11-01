// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[8];
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} Plane;

extern f32 D_801D4DB8;

f32 func_800BFB14(Plane *plane, f32 x, f32 z) {
    return (((plane->unk8 * x + plane->unkC * z) * D_801D4DB8) + plane->unkE) / (-plane->unkA * D_801D4DB8);
}
