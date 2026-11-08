// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void DynaPoly_NullPolyList(struct CollisionPoly **polyList) {
    *polyList = 0;
}
