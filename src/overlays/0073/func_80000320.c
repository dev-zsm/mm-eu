// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0073.h"

void func_800FEE3C(u8 *, f32, f32);

void func_80000320(u8 *arg0) {
    func_800FEE3C(arg0 + 0x68, 0.0f, 2.0f);
    func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0x8C) + M2C_FIELD(arg0, f32 *, 0x28) - 1.0f, 2.0f);
}
