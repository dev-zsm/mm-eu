// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    u8 pad0[0xA];
    u8 unkA;
    u8 unkB;
    u8 unkC[2];
    u8 unkE[2];
} S;
#define DECR(x) ((x) == 0 ? 0 : ((x) -= 1))
void Math_StepToS(u8 *, s32, s32);
void func_800B5DD8(s32 arg0, S *s) {
    if (DECR(s->unkB) == 0) {
        if (DECR(s->unkA) == 0) {
            Math_StepToS(s->unkC, 0, 0x1E);
            Math_StepToS(s->unkE, 0, 0x46);
            return;
        }
        Math_StepToS(s->unkC, 0xFF, 0xA);
        Math_StepToS(s->unkE, 0xFF, 0x14);
    }
}
