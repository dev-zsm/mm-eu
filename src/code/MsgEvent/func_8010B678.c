// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_CheckItem(Actor* actor, PlayState* play, u8** script, MsgScriptCallback callback, s32* endScript) {
    MsgScriptCmdCheckItem* cmd = (MsgScriptCmdCheckItem*)*script;
    u16 item = SCRIPT_PACK_16(cmd->itemH, cmd->itemL);
    s16 skip = SCRIPT_PACK_16(cmd->offsetH, cmd->offsetL);

    if (INV_CONTENT(item) == item) {
        *script += skip;
    }
    return false;
}
