// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098020;
extern u8 D_8009D288[];
void __osSiCreateAccessQueue(void);
void osRecvMesg(void *a, void *b, s32 c);

void __osSiGetAccess(void) {
    s32 sp1C;

    if (D_80098020 == 0) {
        __osSiCreateAccessQueue();
    }
    osRecvMesg(D_8009D288, &sp1C, 1);
}
