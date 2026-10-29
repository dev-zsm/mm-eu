#include "types.h"

extern void func_80A02B40();
extern void func_80A02A48();

void func_80000408(u8 *a0) {
    *(s32 *)(a0 + 0x4A8) = 0;
    func_80A02B40(a0);
    func_80A02A48(a0);
}
