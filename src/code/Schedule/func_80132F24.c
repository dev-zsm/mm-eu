// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_schedule.h"

s32 Schedule_ReturnTime(PlayState* play, u8** script, ScheduleOutput* output) {
    ScheduleCmdReturnTime* cmd = (ScheduleCmdReturnTime*)*script;
    f32 f;
    u16 time0;
    u16 time1;

    SCRIPT_CALC_TIME(cmd->time0Hr, cmd->time0Min, time0, f);

    SCRIPT_CALC_TIME(cmd->time1Hr, cmd->time1Min, time1, f);
    time1--;

    output->result = cmd->result;
    output->time0 = time0;
    output->time1 = time1;
    output->hasResult = true;

    return true;
}
