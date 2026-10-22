// FLAGS: -O2 -g0
#include "types.h"

extern void osSendMesg(void *a, s32 b, s32 c);
extern u8 D_8009E7C8[];

void __osPiRelAccess(void) {
    osSendMesg(D_8009E7C8, 0, 0);
}
