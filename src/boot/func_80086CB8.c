// FLAGS: -O2 -g0
#include "types.h"

extern f32 D_8009939C;   /* pi/2 */
f32 func_80086C88(void);

/*
 * Single-precision acos: pi/2 - asin(x). The argument is passed in $f12 and forwarded
 * untouched to func_80086C88 (asin), so the C signature stays (void) to keep the codegen.
 */
f32 func_80086CB8(void) {
    return D_8009939C - func_80086C88();
}
