// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "actor.h"
#include "generated/overlays/0129.h"
extern void (*D_808F931C[])(void);
void func_80001024(Actor *thisx) {
    void (*f)(void);
    f = D_808F931C[*(s32 *)((u8 *)thisx + 0x15C)];
    if (f != 0) {
        f();
    }
}
