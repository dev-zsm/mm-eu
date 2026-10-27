#include "types.h"
s32 Math_StepToS(s16 *p, s16 a, s16 b) {
    s16 t;
    if (b != 0) {
        t = *p;
        if (a < t) {
            b *= -1;
        }
        *p = t + b;
        if (((*p - a) * b) >= 0) {
            *p = a;
            return 1;
        }
    } else {
        if (a == *p) {
            return 1;
        }
    }
    return 0;
}
