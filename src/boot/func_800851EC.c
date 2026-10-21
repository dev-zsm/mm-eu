// FLAGS: -O2 -g0
#include "types.h"

s32 func_800851EC(u16 *a0, u16 a1) {
    return ((*a0 & a1) ^ a1) == 0;
}
