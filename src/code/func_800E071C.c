// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 w[6];
} Blk;

extern Blk D_801BADC4;

s32 Collider_InitJntSphElementDim(s32 a0, Blk *a1) {
    *a1 = D_801BADC4;
    return 1;
}
