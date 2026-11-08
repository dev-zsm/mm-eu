// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Collider_SetElementDamageInfoAT(struct PlayState *play, struct ColliderElementDamageInfoAT *dest, struct ColliderElementDamageInfoATInit *src) {
    M2C_FIELD(dest, s32 *, 0) = (s32) M2C_FIELD(src, s32 *, 0);
    M2C_FIELD(dest, u8 *, 4) = (u8) M2C_FIELD(src, u8 *, 4);
    M2C_FIELD(dest, u8 *, 5) = (u8) M2C_FIELD(src, u8 *, 5);
    return 1;
}
