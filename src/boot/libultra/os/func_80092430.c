// FLAGS: -O1 -g0 -mips2
#include "sdk/ultra64.h"

void osSetTime(OSTime time) {
    D_8009E980 = time;
}
