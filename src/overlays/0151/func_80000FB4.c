// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u8 p0[0xBCA]; s16 uBCA; } A;
extern void func_80917B04();
extern void func_80917F70();

void func_80000FB4(A *a, s32 b) {
    func_80917B04(a, b);
    if (a->uBCA == 0) {
        func_80917F70(a, b);
    }
}
