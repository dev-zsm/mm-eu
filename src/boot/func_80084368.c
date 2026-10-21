// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_80096D80;

void func_80084270(void);

void func_80084368(u16 a0) {
    *(u16 *)(D_80096D80 + 0x12) = a0;
    func_80084270();
}
