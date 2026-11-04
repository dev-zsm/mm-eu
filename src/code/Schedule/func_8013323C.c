// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_schedule.h"

s32 Schedule_CheckBeforeTimeL(PlayState* play, u8** script, ScheduleOutput* output) {
    ScheduleCmdCheckBeforeTimeL* cmd = (ScheduleCmdCheckBeforeTimeL*)*script;
    f32 f;
    u16 testTime;
    u16 now;

    SCRIPT_CALC_TIME(cmd->timeHr, cmd->timeMin, testTime, f);

    now = SCRIPT_TIME_NOW;

    if (now < testTime) {
        *script += (s16)SCRIPT_PACK_16(cmd->offsetH, cmd->offsetL);
    }

    return false;
}
