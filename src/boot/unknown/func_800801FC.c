// FLAGS: -O2 -g3 -mips2
#include "os_internal.h"

void func_800801FC(void) {
    u32 sp18[2];

    sp18[0] = D_80000318 + 0x80000000;
    func_80080150((void *)0x80000400, D_80000500);
    func_80080150(D_80025D00, D_80080060);
    func_80080150(D_802006E0, (void *)sp18[0]);
}
