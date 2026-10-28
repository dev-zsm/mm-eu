// FLAGS: -O2 -g0
#include "types.h"

extern u8 D_8009D288[];
void osSendMesg(void *a, s32 b, s32 c);

void __osSiRelAccess(void) {
    osSendMesg(D_8009D288, 0, 0);
}
