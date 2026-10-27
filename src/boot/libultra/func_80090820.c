// FLAGS: -O1 -g0 -mips2
#include "types.h"

extern u32 D_80098050;
u32 __osDisableInt(void);
void __osRestoreInt(u32);

void __osSetGlobalIntMask(u32 arg0) {
    register u32 saveMask;

    saveMask = __osDisableInt();
    D_80098050 |= arg0;
    __osRestoreInt(saveMask);
}
