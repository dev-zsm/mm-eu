#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

void func_80001654(u8 *arg0, s32 arg1, u32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s8 *, 0x528) = 9;
    if (arg3 >= 0x1F) {
        M2C_FIELD(arg0, s8 *, 0x52A) = 0;
    } else {
        M2C_FIELD(arg0, s8 *, 0x52A) = 0x39;
    }
    M2C_FIELD(arg0, s8 *, 0x544) = 2;
    M2C_FIELD(arg0, s8 *, 0x545) = 5;
    M2C_FIELD(arg0, s16 *, 0x558) = arg3;
    M2C_FIELD(arg0, s32 *, 0x530) = arg1;
    M2C_FIELD(arg0, s8 *, 0x535) = arg2;
    if (arg1 & 0x400) {
        M2C_FIELD(arg0, s8 *, 0x529) = 0;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x52C) = 0xA;
    M2C_FIELD(arg0, s32 *, 0x538) = 0xF7CFFFFF;
    if (arg1 & 0x80000) {
        M2C_FIELD(arg0, s8 *, 0x529) = 0;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x529) = 0x11;
}
