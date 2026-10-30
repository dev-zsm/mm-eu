#include "types.h"
extern u8 D_80AFB130[];
void func_80AFA4C0();
void func_80000C34(u8 *a0, s32 a1) {
    func_80AFA4C0(a0, 0x284F);
    *(u8 *)(a0 + 0x1C0) = 0;
    *(u8 **)(a0 + 0x1AC) = D_80AFB130;
}
