#include "types.h"
#include "code_funcs.h"

extern void CollisionHeader_SegmentedToVirtual(s32 arg0);

void CollisionHeader_GetVirtual(s32 arg0, s32 *out) {
    *out = func_80100304(arg0);
    CollisionHeader_SegmentedToVirtual(*out);
}
