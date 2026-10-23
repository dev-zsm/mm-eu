// FLAGS: -O2 -g0 -mips2
#include "types.h"
s32 CollisionCheck_NoSharedFlags(s32 *a0, s32 *a1) {
    s32 r = 0;
    if ((a1[2] & a0[0]) == 0) {
        return 1;
    }
    return r;
}
