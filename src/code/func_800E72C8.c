// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void CollisionCheck_SetInfoNoDamageTable(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u8 *, 0x17) = (u8) M2C_FIELD(arg1, u8 *, 0);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) M2C_FIELD(arg1, s16 *, 2);
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) M2C_FIELD(arg1, s16 *, 4);
    M2C_FIELD(arg0, u8 *, 0x16) = (u8) M2C_FIELD(arg1, u8 *, 6);
}
