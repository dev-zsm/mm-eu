#include "types.h"

s32 MsgEvent_CheckCallbackMulti(s32 a0, s32 a1, u8 **pp, s32 (*cb)(s32, s32)) {
    u8 *p;
    s32 r;
    s16 off;

    p = *pp;
    r = 1;
    if (cb != 0) {
        r = cb(a0, a1);
    }
    switch (r) {
        case 3:
            off = p[6] | (p[5] << 8);
            break;
        case 2:
            off = p[4] | (p[3] << 8);
            break;
        case 1:
            off = p[2] | (p[1] << 8);
            break;
        default:
            return 1;
    }
    *pp += off;
    return 0;
}
