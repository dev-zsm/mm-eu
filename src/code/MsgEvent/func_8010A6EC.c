// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_CheckTextChoice(Actor* actor, PlayState* play, u8** script, MsgScriptCallback callback, s32* endScript) {
    MsgScriptCmdCheckTextChoice* cmd = (MsgScriptCmdCheckTextChoice*)*script;
    s16 skip = 0;

    switch (*((u8 *)play + 0x1692D)) {
        case 0:
            skip = SCRIPT_PACK_16(cmd->offset0H, cmd->offset0L);
            break;

        case 1:
            skip = SCRIPT_PACK_16(cmd->offset1H, cmd->offset1L);
            break;

        case 2:
            skip = SCRIPT_PACK_16(cmd->offset2H, cmd->offset2L);
            break;

        default:
            break;
    }
    *script += skip;

    return false;
}
