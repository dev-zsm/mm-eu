// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 DamageTable_Get(M2C_UNK);                         /* extern */
M2C_UNK CollisionCheck_SetInfo2(s32, s32, s32);               /* extern */

void CollisionCheck_SetInfoGetDamageTable(struct CollisionCheckInfo *info, s32 index, struct CollisionCheckInfoInit2 *init) {
    CollisionCheck_SetInfo2(info, DamageTable_Get(index), init);
}
