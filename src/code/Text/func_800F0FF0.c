#include "types.h"

extern s32 Player_GetMask(void *);
extern u16 D_801BCF4E[][19];

u16 Text_GetFaceReaction(void *play, s32 reactionSet) {
    if ((Player_GetMask(play) > 0) && (Player_GetMask(play) < 20)) {
        return D_801BCF4E[reactionSet][Player_GetMask(play)];
    }
    return 0;
}
