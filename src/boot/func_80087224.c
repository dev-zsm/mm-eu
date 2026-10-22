// FLAGS: -O2 -g0
#include "types.h"
void osRecvMesg(s32 a, s32 b, s32 c);
void ArenaImpl_Unlock(s32 arg0) {
    osRecvMesg(arg0 + 8, 0, 1);
}
