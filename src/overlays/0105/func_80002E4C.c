// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8016A23C();
void func_808C49E0();
void func_801A3D04();
void func_808C5B2C();

void func_80002E4C(u8 *arg0, s32 arg1) {
    if (func_8016A23C(arg1) == 0) {
        func_808C49E0(arg1);
        M2C_FIELD(arg0, u8 *, 0x819) |= 1;
        func_801A3D04(0x38);
        func_808C5B2C(arg0);
    }
}
