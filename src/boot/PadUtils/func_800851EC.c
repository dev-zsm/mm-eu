// FLAGS: -O2 -g0
#include "types.h"

s32 PadUtils_CheckCur(u16 *a0, u16 a1) {
    return ((*a0 & a1) ^ a1) == 0;
}
