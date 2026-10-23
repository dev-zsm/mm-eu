// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void func_80151E7C();
void Actor_ContinueText(u8 *a0, u8 *a1, u16 a2) {
    func_80151E7C(a0, a2);
    *(u16 *)(a1 + 0x116) = a2;
}
