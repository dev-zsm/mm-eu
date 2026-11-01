// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"

f32 func_8008704C();                                /* extern */

f32 Environment_RandCentered(void) {
    return func_8008704C() - 0.5f;
}
