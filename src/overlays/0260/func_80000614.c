// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809901E8;

void func_80000614(u8 *arg0) {
    s16 temp_v0;

    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    temp_v0 = M2C_FIELD(arg0, s16 *, 0xC0);
    M2C_FIELD(arg0, M2C_UNK **, 0x19C) = &D_809901E8;
    M2C_FIELD(arg0, s32 *, 0x194) = 0;
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0xBC) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x34) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x30) = temp_v0;
}
