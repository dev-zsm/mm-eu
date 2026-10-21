// FLAGS: -O1 -g0 -mips2 -trapuv
#include "types.h"

void func_80084434(void);
void func_800847DC(s32 a0, s32 *a1);

// best attempt: 1 instr differs (ROM has a nop in the jal delay slot, ours spills f12 there)
void func_8008487C(f64 a0, s32 a2, s32 a3) {
    s32 pad[2];

    func_80084434();
    func_800847DC(a2, &a3);
}
