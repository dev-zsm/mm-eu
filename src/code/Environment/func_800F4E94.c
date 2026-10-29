#include "types.h"

typedef struct {
    s32 shift;
    s32 base;
} ZBufRange;
extern ZBufRange D_801BF044[8];
s32 Environment_ZBufValToFixedPoint(s32 zBufVal) {
    ZBufRange *new_var;
    ZBufRange *range = &D_801BF044[((zBufVal ^ 0) >> 15) & 7];
    new_var = range;
    return new_var->base + ((((zBufVal ^ 0) >> 4) & 0x7FF) << range->shift);
}
