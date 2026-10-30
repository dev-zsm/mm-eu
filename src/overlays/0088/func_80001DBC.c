#include "types.h"

extern void func_80151E7C();
extern void func_808A77C0();
extern u8 D_808A9944[];

void func_80001DBC(s32 a0, s32 a1, u16 a2) {
    func_80151E7C(a0, a2 & 0xFFFF);
    func_808A77C0(a1, D_808A9944);
}
