#include "types.h"

s32 SubS_TimePathing_ComputeProgress(f32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 *arg6) {
    s32 i;
    s32 j;
    s32 cnt;
    s32 ret;
    f32 inv;

    *arg0 = 0.0f;
    if (arg2 <= 0 || arg1 < 0) {
        return 0;
    }
    inv = 1.0f / arg2;
    cnt = 0;
    for (i = arg5 - 1; i < arg4; i++) {
        for (j = 0; j < arg2; j++) {
            if (cnt == arg1) {
                break;
            }
            *arg0 += (arg6[i + 1] - arg6[i]) * inv;
            cnt++;
        }
    }
    if (arg1 == arg3) {
        ret = 2;
    } else {
        ret = 1;
    }
    return ret;
}
