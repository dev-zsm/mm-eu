// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void CollisionCheck_DisableSAC(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, u16 *, 2) = (u16) (M2C_FIELD(arg1, u16 *, 2) & 0xFFFE);
}
