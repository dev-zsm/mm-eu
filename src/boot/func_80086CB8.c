// FLAGS: -O2 -g0
#include "types.h"

extern f32 D_8009939C;   /* pi/2 */
f32 Math_FAsinF(void);

/*
 * Single-precision acos: pi/2 - asin(x). The argument is passed in $f12 and forwarded
 * untouched to Math_FAsinF (asin), so the C signature stays (void) to keep the codegen.
 */
f32 Math_FAcosF(void) {
    return D_8009939C - Math_FAsinF();
}
