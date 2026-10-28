// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */

f32 func_80001FF4(void) {
    return func_8008704C() - 0.5f;
}
