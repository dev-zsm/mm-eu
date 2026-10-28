// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800001A8(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) & 0xFFFDFFFF);
    M2C_FIELD(arg0, s8 *, 0xADB) = 0;
    M2C_FIELD(arg0, s32 *, 0xBD0) = 0;
    M2C_FIELD(arg0, s32 *, 0xBB4) = 0;
    M2C_FIELD(arg0, s32 *, 0xB98) = 0;
}
