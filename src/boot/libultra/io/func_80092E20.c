// FLAGS: -O2 -g0 -mips2
#include "types.h"
void __osSiGetAccess(s32 a0);
void __osSiRelAccess(void);
extern u8 D_8009D2E0;
extern u8 D_8009D2E1;
s32 osContSetCh(s32 a0) {
    u8 v = a0;
    __osSiGetAccess(a0);
    v = a0;
    if (v >= 5) {
        D_8009D2E1 = 4;
    } else {
        D_8009D2E1 = v;
    }
    D_8009D2E0 = 0xFE;
    __osSiRelAccess();
    return 0;
}
