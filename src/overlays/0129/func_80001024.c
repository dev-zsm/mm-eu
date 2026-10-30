// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void (*D_808F931C[])(void);
void func_80001024(u8 *a) {
    void (*f)(void);
    f = D_808F931C[*(s32 *)(a + 0x15C)];
    if (f != 0) {
        f();
    }
}
