// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 __osDisableInt(void);
extern void __osRestoreInt(s32 a0, void *a1);
extern u8 D_8009807C[];

s32 osEPiLinkHandle(void *arg0) {
    s32 temp_a0;

    temp_a0 = __osDisableInt();
    *(void **)arg0 = *(void **)&D_8009807C;
    *(void **)&D_8009807C = arg0;
    __osRestoreInt(temp_a0, arg0);
    return 0;
}
