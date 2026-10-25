#include "types.h"

extern u8 D_801D3DF0;
extern u8 D_801D3DF4;
extern u32 D_801F7580[];

s32 AudioSeq_IsSeqCmdNotQueued(u32 cmdVal, u32 cmdMask) {
    u8 i;

    for (i = D_801D3DF4; i != D_801D3DF0; i++) {
        if ((D_801F7580[i] & cmdMask) == cmdVal) {
            return 0;
        }
    }
    return 1;
}
