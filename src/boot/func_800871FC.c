// FLAGS: -O2 -g0
#include "types.h"
void osSendMesg(s32 a, s32 b, s32 c);
void ArenaImpl_Lock(s32 arg0) {
    osSendMesg(arg0 + 8, 0, 1);
}
