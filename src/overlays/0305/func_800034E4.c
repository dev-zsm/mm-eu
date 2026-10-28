// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A0B2F0;

void func_800034E4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1A8) = &D_80A0B2F0;
    M2C_FIELD(arg0, s16 *, 0x28C) = 0;
    M2C_FIELD(arg0, s16 *, 0x28E) = 0;
    M2C_FIELD(arg0, s16 *, 0x288) = 0x83F;
    M2C_FIELD(arg0, s16 *, 0x28A) = 0xBB8;
    M2C_FIELD(arg0, s16 *, 0x294) = 0x1F4;
    M2C_FIELD(arg0, s16 *, 0x29E) = 0x1F4;
    M2C_FIELD(arg0, s16 *, 0x2A0) = 0x28;
    M2C_FIELD(arg0, f32 *, 0x284) = 7.0f;
}
