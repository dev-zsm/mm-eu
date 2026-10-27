// FLAGS: -O2 -g3
#include "types.h"

extern u32 D_8009C200;
extern u32 D_8009C204;

void func_80081944(void) {
    D_8009C200 = *(u32 *)0xA02FB1F4;
    D_8009C204 = *(u32 *)0xA02FE1C0;
}
