// FLAGS: -O2 -g0
#include "types.h"

extern void func_80083EAC(void *a0, s32 a1);
extern u8 D_80099340[];

void func_80086324(void) {
    func_80083EAC(D_80099340, 0);
}
