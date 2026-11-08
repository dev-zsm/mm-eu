// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Animation_SetMorph(struct PlayState *play, struct SkelAnime *skelAnime, f32 morphFrames) {
    M2C_FIELD(skelAnime, f32 *, 0x28) = 1.0f;
    M2C_FIELD(skelAnime, f32 *, 0x2C) = (f32) (1.0f / morphFrames);
}
