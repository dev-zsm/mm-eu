// FLAGS: -O1 -g0 -mips2
#include "types.h"

extern u32 D_8009E990;
extern void *__osDisableInt(void);
extern u32 osGetCount(void);
extern void __osSetCompare(u32 a);
extern void __osRestoreInt(void *a);

void __osSetTimerIntr(u64 v) {
    u64 sum;
    void *s;

    if (v < 0x1D4) {
        v = 0x1D4;
    }
    s = __osDisableInt();
    D_8009E990 = osGetCount();
    sum = v + D_8009E990;
    __osSetCompare((u32)sum);
    __osRestoreInt(s);
}
