// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Math3D_SphVsSphOverlap(void *, void *, s32 *);

void Math3D_SphVsSph(void *arg0, void *arg1) {
    s32 sp1C;

    Math3D_SphVsSphOverlap(arg0, arg1, &sp1C);
}
