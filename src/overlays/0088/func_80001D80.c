#include "types.h"
extern u8 D_808A98D0[];
void func_80151E7C();
void func_808A77C0();
void func_80001D80(s32 a0, s32 a1, u16 a2) {
    func_80151E7C(a0, a2 & 0xFFFF);
    func_808A77C0(a1, D_808A98D0);
}
