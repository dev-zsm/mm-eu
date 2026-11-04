// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

void PlayerAnimation_Change(PlayState* play, SkelAnime* skelAnime, PlayerAnimationHeader* animation, f32 playSpeed,
                            f32 startFrame, f32 endFrame, u8 mode, f32 morphFrames) {
    skelAnime->mode = mode;
    if ((morphFrames != 0.0f) && ((animation != skelAnime->animation) || (startFrame != skelAnime->curFrame))) {
        if (morphFrames < 0) {
            PlayerAnimation_SetUpdateFunction(skelAnime);
            SkelAnime_CopyFrameTable(skelAnime, skelAnime->morphTable, skelAnime->jointTable);
            morphFrames = -morphFrames;
        } else {
            skelAnime->update.player = PlayerAnimation_Morph;
            AnimTaskQueue_AddLoadPlayerFrame(play, animation, (s32)startFrame, skelAnime->limbCount,
                                             skelAnime->morphTable);
        }
        skelAnime->morphWeight = 1.0f;
        skelAnime->morphRate = 1.0f / morphFrames;
    } else {
        PlayerAnimation_SetUpdateFunction(skelAnime);
        AnimTaskQueue_AddLoadPlayerFrame(play, animation, (s32)startFrame, skelAnime->limbCount, skelAnime->jointTable);
        skelAnime->morphWeight = 0.0f;
    }

    skelAnime->animation = animation;
    skelAnime->curFrame = 0.0f;
    skelAnime->startFrame = startFrame;
    skelAnime->curFrame = startFrame;
    skelAnime->endFrame = endFrame;
    skelAnime->animLength = Animation_GetLength(animation);
    skelAnime->playSpeed = playSpeed;
}
