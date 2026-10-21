// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u64 func_800905C0(void);
extern void func_80081E8C(s32);
extern u8 *D_8009C220;

void func_80082BA0(void) {
    u64 start;
    u64 now;

    start = func_800905C0();
    do {
        func_80081E8C(0x10);
        now = func_800905C0();
    } while (now - start < 0xDF84759ULL);
    D_8009C220[0x7CF] = 1;
}
