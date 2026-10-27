// FLAGS: -O2 -g0 -mips2
#include "types.h"

s8 PadUtils_GetRelYImpl(s8 *arg0) {
    return arg0[0x15];
}
