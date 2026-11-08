#include "types.h"

extern s32 Player_OverrideLimbDrawGameplayCommon(void *arg0, s32 arg1, s32 *arg2, void *arg3, void *arg4, void *arg5);

s32 Player_OverrideLimbDrawGameplayCrawling(struct PlayState *play, s32 limbIndex, union Gfx **dList, struct Vec3f *pos, struct Vec3s *rot, struct Actor *thisx) {
    if (Player_OverrideLimbDrawGameplayCommon(play, limbIndex, dList, pos, rot, thisx) == 0) {
        *dList = 0;
    }
    return 0;
}
