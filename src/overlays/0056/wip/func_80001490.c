// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 func_8082E37C();

s32 func_80001490(u8 *a0) {
    if (func_8082E37C(a0) != 0) {
        return *(s16 *)(a0 + 0xACC) != 0;
    }
    return 0;
}
