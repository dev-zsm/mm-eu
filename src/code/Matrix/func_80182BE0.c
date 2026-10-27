// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void *D_801F3644;
void Matrix_MultZero(f32 *a0) {
    f32 *m = D_801F3644;
    a0[0] = m[12];
    a0[1] = m[13];
    a0[2] = m[14];
}
