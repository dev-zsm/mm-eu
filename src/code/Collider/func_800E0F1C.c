#include "types.h"

typedef struct {
    u32 w[3];
} Dim12;

s32 Collider_SetCylinderDim(s32 arg0, Dim12 __unaligned *dst, Dim12 __unaligned *src) {
    *dst = *src;
    return 1;
}
