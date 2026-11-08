// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void DynaPoly_NullVtxList(struct Vec3s **vtxList) {
    *vtxList = 0;
}
