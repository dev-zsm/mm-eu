#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 value;
} ScheduleCmd;

typedef struct {
    u8 value;
    u8 pad1[0xB];
    s32 isSet;
} ScheduleResult;

s32 Schedule_ReturnValueS(s32 arg0, ScheduleCmd **cmd, ScheduleResult *result) {
    ScheduleCmd *cur = *cmd;

    result->value = cur->value;
    result->isSet = 1;
    return 1;
}
