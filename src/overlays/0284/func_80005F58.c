// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0284.h"

void func_800FFC68(u8 *, f32, f32, u8 *);
void func_809BB004();

void func_80005F58(u8 *arg0, s32 arg1) {
    func_800FFC68(arg0 + 0x70, 1.0f, 1.0f, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x14E) == 0) {
        func_809BB004(arg0, arg1);
    }
}
