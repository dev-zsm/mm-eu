// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"


s32 Math3D_SphVsSph(struct Sphere16 *sphereA, struct Sphere16 *sphereB) {
    s32 sp1C;

    Math3D_SphVsSphOverlap(sphereA, sphereB, &sp1C);
}
