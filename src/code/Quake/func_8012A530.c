// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

f32 func_8008704C();                                /* extern */

f32 Quake_Random(void) {
    return 2.0f * (func_8008704C() - 0.5f);
}
