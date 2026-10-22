// FLAGS: -O2 -g0
#include "types.h"
void bzero(s32 a, s32 b);
void func_8008736C(s32 arg0) {
    bzero(arg0, 0x24);
}
