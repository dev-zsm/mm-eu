#include "types.h"
extern u8 D_809F369C[];
void func_80151E7C();
void func_809F15DC();
void func_80001CCC(s32 a0, s32 a1, u16 a2) {
    func_80151E7C(a0, a2 & 0xFFFF);
    func_809F15DC(a1, D_809F369C);
}
