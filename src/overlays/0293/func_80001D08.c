#include "types.h"

extern void func_80151E7C();
extern void func_809F15DC();
extern u8 D_809F3710[];

void func_80001D08(s32 a0, s32 a1, u16 a2) {
    func_80151E7C(a0, a2 & 0xFFFF);
    func_809F15DC(a1, D_809F3710);
}
