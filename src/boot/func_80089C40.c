// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_80098020;
extern u8 D_8009D280[];
extern u8 D_8009D288[];
void osCreateMesgQueue(void *a, void *b, s32 c);
void osSendMesg(void *a, s32 b, s32 c);

void __osSiCreateAccessQueue(void) {
    D_80098020 = 1;
    osCreateMesgQueue(D_8009D288, D_8009D280, 1);
    osSendMesg(D_8009D288, 0, 0);
}
