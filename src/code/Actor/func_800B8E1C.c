// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Actor_PlaySeq_FlaggedMusicBoxHouse(struct Actor *actor) {
    M2C_FIELD(actor, u8 *, 0x39) = (u8) (M2C_FIELD(actor, u8 *, 0x39) | 0x40);
}
