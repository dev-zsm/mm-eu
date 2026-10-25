#include "types.h"

typedef struct {
    s32 words[13];
} TrisElementDim;

extern TrisElementDim D_801BADE8;

s32 Collider_InitTrisElementDim(void *arg0, TrisElementDim *dim) {
    *dim = D_801BADE8;
    return 1;
}
