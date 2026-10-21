// FLAGS: -O1 -g0 -mips2 -trapuv
#include "types.h"

void func_80084434(void);
void func_800847DC(s32 a0, s32 *a1);

// best attempt: ROM spills only a2/a3 (0x28/0x2C), not a0/a1
void func_8008487C(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 pad[2];

    func_80084434();
    func_800847DC(a2, &a3);
}
