// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000160C(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x52C) = 5;
    M2C_FIELD(arg0, s8 *, 0x528) = 0;
    M2C_FIELD(arg0, s8 *, 0x529) = 0x11;
    M2C_FIELD(arg0, s8 *, 0x52A) = 0x39;
    M2C_FIELD(arg0, s8 *, 0x544) = 1;
    M2C_FIELD(arg0, s32 *, 0x530) = 0;
    M2C_FIELD(arg0, s32 *, 0x538) = 0xF7CFFFFF;
    M2C_FIELD(arg0, s8 *, 0x545) = 0;
    M2C_FIELD(arg0, s16 *, 0x558) = 0xC;
}
