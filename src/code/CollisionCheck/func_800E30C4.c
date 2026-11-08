// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void CollisionCheck_SetBounce(struct Collider *at, struct Collider *ac) {
    M2C_FIELD(at, u8 *, 0x10) = (u8) (M2C_FIELD(at, u8 *, 0x10) | 4);
    M2C_FIELD(ac, u8 *, 0x11) = (u8) (M2C_FIELD(ac, u8 *, 0x11) | 0x80);
}
