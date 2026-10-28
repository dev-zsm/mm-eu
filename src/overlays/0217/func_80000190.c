// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */

f32 func_80000190(f32 arg0, f32 arg1) {
    return ((2.0f * (func_8008704C() * arg1)) - arg1) + arg0;
}
