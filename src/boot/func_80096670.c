// FLAGS: -O2 -g0 -mips2
#include "types.h"
s32 __osDisableInt(void);
void __osRestoreInt(s32 a0);
typedef struct { s32 pad0; s32 unk4; } Blk;
extern Blk *D_800982B0;
s32 osViGetCurrentFramebuffer(void) {
    s32 temp_a0;
    s32 sp18;
    temp_a0 = __osDisableInt();
    sp18 = D_800982B0->unk4;
    __osRestoreInt(temp_a0);
    return sp18;
}
