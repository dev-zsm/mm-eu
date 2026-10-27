#include "types.h"

extern s32 func_80100304(s32 arg0);
extern void CollisionHeader_SegmentedToVirtual(s32 arg0);

void CollisionHeader_GetVirtual(s32 arg0, s32 *out) {
    *out = func_80100304(arg0);
    CollisionHeader_SegmentedToVirtual(*out);
}
