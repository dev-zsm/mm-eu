#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 hi;
    u8 lo;
} MsgScript;

extern void func_80115C10(s16 amount);

s32 MsgEvent_ChangeRupees(void *play, void *font, MsgScript **script, s32 unused) {
    MsgScript *cmd = *script;

    func_80115C10((cmd->hi << 8) | cmd->lo);
    return 0;
}
