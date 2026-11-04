// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_schedule.h"

s32 Schedule_CheckNotInSceneS(PlayState* play, u8** script, ScheduleOutput* output) {
    ScheduleCmdCheckNotInSceneS* cmd = (ScheduleCmdCheckNotInSceneS*)*script;
    s16 sceneId = SCRIPT_PACK_16(cmd->sceneIdH, cmd->sceneIdL);

    if (sceneId != play->sceneId) {
        *script += cmd->offset;
    }

    return false;
}
