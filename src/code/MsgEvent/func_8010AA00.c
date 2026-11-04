// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_CheckDay(Actor* actor, PlayState* play, u8** script, MsgScriptCallback callback, s32* endScript) {
    MsgScriptCmdCheckDay* cmd = (MsgScriptCmdCheckDay*)*script;
    s16 skip = 0;

    switch (gSaveContext.save.day) {
        case 1:
            if (!gSaveContext.save.isNight) {
                skip = SCRIPT_PACK_16(cmd->offsetDay1H, cmd->offsetDay1L);
            } else {
                skip = SCRIPT_PACK_16(cmd->offsetNight1H, cmd->offsetNight1L);
            }
            break;

        case 2:
            if (!gSaveContext.save.isNight) {
                skip = SCRIPT_PACK_16(cmd->offsetDay2H, cmd->offsetDay2L);
            } else {
                skip = SCRIPT_PACK_16(cmd->offsetNight2H, cmd->offsetNight2L);
            }
            break;

        case 3:
            if (!gSaveContext.save.isNight) {
                skip = SCRIPT_PACK_16(cmd->offsetDay3H, cmd->offsetDay3L);
            } else {
                skip = SCRIPT_PACK_16(cmd->offsetNight3H, cmd->offsetNight3L);
            }
            break;

        default:
            break;
    }
    *script += skip;
    return false;
}
