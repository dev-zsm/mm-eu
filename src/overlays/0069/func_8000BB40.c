// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */

s32 func_8000BB40(f32 arg0) {
    return (s32) (func_8008704C() * arg0);
}
