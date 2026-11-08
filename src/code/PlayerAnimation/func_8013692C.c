// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Animation_GetLastFrame(s32);                             /* extern */
M2C_UNK PlayerAnimation_Change(s32, s32, s32, M2C_UNK, f32, f32, s32, f32); /* extern */

void PlayerAnimation_PlayOnce(struct PlayState *play, struct SkelAnime *skelAnime, struct PlayerAnimationHeader *animation) {
    PlayerAnimation_Change(play, skelAnime, animation, 0x3F800000, 0.0f, (f32) Animation_GetLastFrame(animation), 2, 0.0f);
}
