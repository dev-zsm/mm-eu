#include "types.h"

extern void Actor_ChangeFocus();

s32 MsgEvent_FocusToChild(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *child = *(void **)(arg0 + 0x124);

    if (child != 0) {
        Actor_ChangeFocus(arg0, arg1, child);
    }
    return 0;
}
