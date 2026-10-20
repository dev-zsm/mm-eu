// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 *D_8009C220;

void func_80081F04(void) {
    u8 *p = D_8009C220;
    ((void (*)(u8 *))(*(void **)(p + 0x7D4)))(p + 0x7E4);
}
