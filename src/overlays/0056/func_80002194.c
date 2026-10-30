// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 func_8082F218(s32);
s32 func_801238E4(s32);
s32 func_80002194(s32 a) {
    return func_8082F218(a) != 0 || func_801238E4(a) != 0;
}
