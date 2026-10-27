// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Collider_SetBase(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    M2C_FIELD(arg1, s32 *, 0) = arg2;
    M2C_FIELD(arg1, u8 *, 0x14) = (u8) M2C_FIELD(arg3, u8 *, 0);
    M2C_FIELD(arg1, u8 *, 0x10) = (u8) M2C_FIELD(arg3, u8 *, 1);
    M2C_FIELD(arg1, u8 *, 0x11) = (u8) M2C_FIELD(arg3, u8 *, 2);
    M2C_FIELD(arg1, u8 *, 0x12) = (u8) M2C_FIELD(arg3, u8 *, 3);
    M2C_FIELD(arg1, u8 *, 0x13) = (u8) M2C_FIELD(arg3, u8 *, 4);
    M2C_FIELD(arg1, u8 *, 0x15) = (u8) M2C_FIELD(arg3, u8 *, 5);
    return 1;
}
