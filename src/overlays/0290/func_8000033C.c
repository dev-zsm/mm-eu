// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0290.h"

void func_800FFC68(u8 *, f32, f32);

void func_8000033C(u8 *arg0, f32 arg1) {
    func_800FFC68(arg0 + 0x70, 1.0f, arg1);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 0x18) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
}
