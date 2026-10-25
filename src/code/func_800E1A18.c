#include "types.h"

typedef struct {
    s32 w[16];
} Struct_800E1A18;

extern Struct_800E1A18 D_801BAE1C;

s32 Collider_InitQuadDim(s32 arg0, Struct_800E1A18 *arg1) {
    *arg1 = D_801BAE1C;
    return 1;
}
