// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098090;
extern u8 D_8009E7C8[];
extern void __osPiCreateAccessQueue(void);
extern void osRecvMesg(void *a, void *b, s32 c);

void __osPiGetAccess(void) {
    s32 sp1C;

    if (D_80098090 == 0) {
        __osPiCreateAccessQueue();
    }
    osRecvMesg(D_8009E7C8, &sp1C, 1);
}
