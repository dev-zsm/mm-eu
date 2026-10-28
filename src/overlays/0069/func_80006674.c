#include "types.h"

extern void func_808814E8(u8 *);

void func_80006674(u8 *a0) {
    *(f32 *)(a0 + 0x1BC) = 0.0f;
    func_808814E8(a0);
}
