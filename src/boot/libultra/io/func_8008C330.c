// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098090;
extern u8 D_8009E7C8[];
extern u8 D_8009E7C0[];
extern void osCreateMesgQueue(void *a, void *b, s32 c);
extern void osSendMesg(void *a, s32 b, s32 c);

void __osPiCreateAccessQueue(void) {
    D_80098090 = 1;
    osCreateMesgQueue(D_8009E7C8, D_8009E7C0, 1);
    osSendMesg(D_8009E7C8, 0, 0);
}
