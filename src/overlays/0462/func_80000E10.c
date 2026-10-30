#include "types.h"
extern void func_80AFA4C0();
extern u8 D_80AFB310[];
typedef struct { u8 pad0[0x1AC]; void *fn; u8 pad1[0x10]; u8 f; } A;
void func_80000E10(A *a, s32 b) {
    func_80AFA4C0(a, 0x2860);
    a->f = 1;
    a->fn = D_80AFB310;
}
