// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 DamageTable_Get(M2C_UNK);                         /* extern */
M2C_UNK CollisionCheck_SetInfo2(s32, s32, s32);               /* extern */

void CollisionCheck_SetInfoGetDamageTable(s32 arg0, M2C_UNK arg1, s32 arg2) {
    CollisionCheck_SetInfo2(arg0, DamageTable_Get(arg1), arg2);
}
