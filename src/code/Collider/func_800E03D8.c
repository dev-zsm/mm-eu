// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Collider_SetBase(struct PlayState *play, struct Collider *col, struct Actor *actor, struct ColliderInit *src) {
    M2C_FIELD(col, s32 *, 0) = actor;
    M2C_FIELD(col, u8 *, 0x14) = (u8) M2C_FIELD(src, u8 *, 0);
    M2C_FIELD(col, u8 *, 0x10) = (u8) M2C_FIELD(src, u8 *, 1);
    M2C_FIELD(col, u8 *, 0x11) = (u8) M2C_FIELD(src, u8 *, 2);
    M2C_FIELD(col, u8 *, 0x12) = (u8) M2C_FIELD(src, u8 *, 3);
    M2C_FIELD(col, u8 *, 0x13) = (u8) M2C_FIELD(src, u8 *, 4);
    M2C_FIELD(col, u8 *, 0x15) = (u8) M2C_FIELD(src, u8 *, 5);
    return 1;
}
