#include "types.h"

extern s32 Player_OverrideLimbDrawGameplayCommon(void *arg0, s32 arg1, s32 *arg2, void *arg3, void *arg4, void *arg5);

s32 Player_OverrideLimbDrawGameplayCrawling(void *arg0, s32 arg1, s32 *arg2, void *arg3, void *arg4, void *arg5) {
    if (Player_OverrideLimbDrawGameplayCommon(arg0, arg1, arg2, arg3, arg4, arg5) == 0) {
        *arg2 = 0;
    }
    return 0;
}
