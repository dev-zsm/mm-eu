// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8012FA08(s32, u8, u8 *, s32);            /* extern */

void func_80000154(u8 *arg0, s32 arg1) {
    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, u8 *, 0x14C), arg0, arg1) != 0) {
        M2C_FIELD(arg0, u8 *, 0x1E) = (u8) M2C_FIELD(arg0, u8 *, 0x14C);
        M2C_FIELD(arg0, s32 *, 0x13C) = (s32) M2C_FIELD(arg0, s32 *, 0x150);
        M2C_FIELD(arg0, s32 *, 0x154) = (s32) M2C_FIELD(arg0, s32 *, 0x144);
    }
}
