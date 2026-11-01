#include "types.h"
s32 func_80147B34(s32);
s32 func_801529DC(s32);
s32 MsgEvent_AwaitTextDone(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 v = func_801529DC(a1 + 0x4908);
    switch (v) {
        case 4:
        case 5:
            if (func_80147B34(a1) == 0) {
                return 1;
            }
        case 6:
            if (func_80147B34(a1) != 0) {
                return 0;
            }
            return 1;
        case 2:
            return 0;
        default:
            return 1;
    }
    return 1;
}
