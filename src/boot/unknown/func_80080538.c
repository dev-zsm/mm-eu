// FLAGS: -O2 -g3 -mips2
#include "os_internal.h"

void func_80080538(void *arg) {
    func_800803B0();
    osCreatePiManager(0x96, &D_8009B378, D_8009B2B0, 0x32);
    StackCheck_Init(&D_8009B290, D_8009A990, D_8009A990 + sizeof(D_8009A990), 0, 0x400, D_80098438);
    osCreateThread(&D_8009A7E0, 3, func_80080310, arg, &D_8009B290, 0xC);
    osStartThread(&D_8009A7E0);
    osSetThreadPri(NULL, 0);
    for (;;) {
    }
}
