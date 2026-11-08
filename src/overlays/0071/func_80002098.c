// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8088E6C4();
void func_80137070();

void func_80002098(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x262) & 4) {
        func_8088E6C4(arg0, arg1);
    }
    func_80137070(arg0 + 0x144);
    M2C_FIELD(arg0, void (**)(u8 *, s32), 0x26C)(arg0, arg1);
}
