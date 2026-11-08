#include "types.h"
#include "generated/code_funcs.h"

extern void CollisionHeader_SegmentedToVirtual(s32 arg0);

void CollisionHeader_GetVirtual(struct CollisionHeader *colHeader, struct CollisionHeader **dest) {
    *dest = func_80100304(colHeader);
    CollisionHeader_SegmentedToVirtual(*dest);
}
