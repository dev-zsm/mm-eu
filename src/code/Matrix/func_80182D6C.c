#include "types.h"
void Matrix_MtxFCopy(f32 *a, f32 *b) {
    f32 t0, t1;
    t0 = b[0]; t1 = b[1]; a[0] = t0; a[1] = t1;
    t1 = b[3]; t0 = b[2]; a[2] = t0; a[3] = t1;
    t1 = b[5]; t0 = b[4]; a[4] = t0; a[5] = t1;
    t1 = b[7]; t0 = b[6]; a[6] = t0; a[7] = t1;
    t1 = b[9]; t0 = b[8]; a[8] = t0; a[9] = t1;
    t1 = b[11]; t0 = b[10]; a[10] = t0; a[11] = t1;
    t1 = b[13]; t0 = b[12]; a[12] = t0; a[13] = t1;
    t1 = b[15]; t0 = b[14]; a[14] = t0; a[15] = t1;
}
