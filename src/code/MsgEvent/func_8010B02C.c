// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_CheckEventInf(Actor* actor, PlayState* play, u8** script, MsgScriptCallback callback, s32* endScript) {
    MsgScriptCmdCheckEventInf* cmd = (MsgScriptCmdCheckEventInf*)*script;
    s16 skip = SCRIPT_PACK_16(cmd->offsetH, cmd->offsetL);

    if (gSaveContext.eventInf[cmd->flagByte] & cmd->flagMask) {
        *script += skip;
    }
    return false;
}
