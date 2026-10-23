// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

f32 func_8008704C();

f32 Rand_ZeroFloat(f32 arg0) {
    return func_8008704C() * arg0;
}
