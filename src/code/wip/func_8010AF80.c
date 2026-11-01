#include "types.h"

// Best attempt: ROM reuses a0/a1 as the temporaries (and still spills a0, a1, a3).
s32 MsgEvent_Jump(s32 arg0, s32 arg1, u8 **cursor, s32 arg3) {
    u8 *p = *cursor;

    *cursor = p + (s16)((p[1] << 8) | p[2]);
    return 0;
}
