// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void CollisionCheck_SetBounce(void *arg0, void *arg1) {
    M2C_FIELD(arg0, u8 *, 0x10) = (u8) (M2C_FIELD(arg0, u8 *, 0x10) | 4);
    M2C_FIELD(arg1, u8 *, 0x11) = (u8) (M2C_FIELD(arg1, u8 *, 0x11) | 0x80);
}
