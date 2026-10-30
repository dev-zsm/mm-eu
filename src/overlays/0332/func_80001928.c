#include "types.h"
extern u8 D_80A2BA24[];
void func_80A2A324();
void func_80001928(u8 *a0) {
    func_80A2A324(a0, 3, 0);
    *(s16 *)(a0 + 0x44C) = 0;
    *(u8 **)(a0 + 0x3AC) = D_80A2BA24;
}
