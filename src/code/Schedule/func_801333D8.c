#include "types.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
} Sched;

typedef s32 (*SchedFunc)(s32, u8 **, Sched *);

extern SchedFunc D_801C6910[];
extern u8 D_801C695C[];

s32 Schedule_RunScript(s32 arg0, u8 *arg1, Sched *arg2) {
    s32 r;
    u8 op;
    u8 len;

    do {
        op = *arg1;
        len = D_801C695C[op];
        r = D_801C6910[op](arg0, &arg1, arg2);
        arg1 += len;
    } while (r == 0);
    return arg2->unkC;
}
