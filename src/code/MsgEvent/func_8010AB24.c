#include "types.h"

extern s32 func_801529DC(s32 a);
extern s32 func_80147B34(s32 a);

s32 MsgEvent_AwaitTextJump(s32 arg0, s32 arg1, u8 **arg2, s32 arg3) {
    u8 *p = *arg2;
    s32 off;

    switch (func_801529DC(arg1 + 0x4908)) {
        case 4:
        case 5:
            if (func_80147B34(arg1) == 0) {
                return 1;
            }
        case 2:
            off = (s16)(p[2] | (p[1] << 8));
            break;
        default:
            return 1;
    }
    *arg2 += off;
    return 0;
}
