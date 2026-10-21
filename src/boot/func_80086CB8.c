// FLAGS: -O2 -g0
#include "types.h"

extern f32 D_8009939C;
f32 func_80086C88(void);

f32 func_80086CB8(void) {
    return D_8009939C - func_80086C88();
}
