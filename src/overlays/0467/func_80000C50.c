// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad[0x1C]; s16 v; } S;
extern void func_80B06BD4();
extern void func_80B06D2C();

void func_80000C50(S *a0, s32 a1) {
    if (a0->v == 0) {
        func_80B06BD4(a0, 3);
        func_80B06D2C(a0);
    }
}
