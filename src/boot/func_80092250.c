// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void __osPiGetAccess(void);
extern s32 __osEPiRawReadIo(s32, s32, s32);
extern s32 __osPiRelAccess(void);

s32 osEPiReadIo(s32 a0, s32 a1, s32 a2) {
    volatile s32 sp1C;

    __osPiGetAccess();
    sp1C = __osEPiRawReadIo(a0, a1, a2);
    __osPiRelAccess();
    return sp1C;
}
