#include "types.h"

extern s32 func_801529DC(s32);
extern s32 func_80147B34(s32);

s32 MsgEvent_AwaitTextEnd(s32 a0, s32 a1, s32 a2, s32 a3, s32 *a4) {
    s32 v = func_801529DC(a1 + 0x4908);

    *a4 = 0;
    if (v != 2) {
        if (v == 4 || v == 5) {
            if (func_80147B34(a1) != 0) {
                goto set;
            }
        } else {
            return 1;
        }
    } else {
set:
        *a4 = 1;
    }
    return 1;
}
