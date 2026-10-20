// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D0F0[];
extern void func_800878AC(void *, void *, void *, void *);

void func_80086F3C(void *a0, void *a1, void *a2) {
    func_800878AC(D_8009D0F0, a0, a1, a2);
}
