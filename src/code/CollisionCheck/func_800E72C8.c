// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void CollisionCheck_SetInfoNoDamageTable(struct CollisionCheckInfo *info, struct CollisionCheckInfoInit *init) {
    M2C_FIELD(info, u8 *, 0x17) = (u8) M2C_FIELD(init, u8 *, 0);
    M2C_FIELD(info, s16 *, 0x10) = (s16) M2C_FIELD(init, s16 *, 2);
    M2C_FIELD(info, s16 *, 0x12) = (s16) M2C_FIELD(init, s16 *, 4);
    M2C_FIELD(info, u8 *, 0x16) = (u8) M2C_FIELD(init, u8 *, 6);
}
