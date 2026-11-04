#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 offsetHi;
    u8 offsetLo;
} ScheduleBranch;

s32 Schedule_BranchL(s32 arg0, ScheduleBranch **cmd, s32 arg2) {
    ScheduleBranch *cur = *cmd;

    *cmd = (ScheduleBranch *)((u8 *)cur + (s16)((cur->offsetHi << 8) | cur->offsetLo));
    return 0;
}
