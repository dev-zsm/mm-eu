// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80836DE0();
void func_800B8BDC();
void func_8082D63C();

void func_8000DE68(s32 arg0, u8 *arg1) {
    if (func_80836DE0(arg0, arg1, M2C_FIELD(arg1, s32 *, 0x68), 0x1F4) != 0) {
        func_800B8BDC(arg1, 0x2889);
        if (M2C_FIELD(arg1, s16 *, 0xB6A) >= 0x321) {
            func_8082D63C(arg1, 0x6804);
        }
    }
}
