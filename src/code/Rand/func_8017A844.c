// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "generated/code_funcs.h"

f32 func_8008704C();

f32 Rand_ZeroFloat(f32 scale) {
    return func_8008704C() * scale;
}
