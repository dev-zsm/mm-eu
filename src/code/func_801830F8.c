#include "types.h"

void Matrix_Transpose(f32 *m) {
    f32 t;

    t = m[1];
    m[1] = m[4];
    m[4] = t;
    t = m[2];
    m[2] = m[8];
    m[8] = t;
    t = m[6];
    m[6] = m[9];
    m[9] = t;
}
