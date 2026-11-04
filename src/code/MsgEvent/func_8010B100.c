// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_CheckItemAction(Actor* actor, PlayState* play, u8** script, MsgScriptCallback callback, s32* endScript) {
    MsgScriptCmdCheckItemAction* cmd = (MsgScriptCmdCheckItemAction*)*script;
    PlayerItemAction checkItemAction = SCRIPT_PACK_16(cmd->itemActionH, cmd->itemActionL);
    s16 skip;
    PlayerItemAction curItemAction;

    switch (Message_GetState(&play->msgCtx)) {
        case TEXT_STATE_CHOICE:
        case TEXT_STATE_EVENT:
            if (!Message_ShouldAdvance(play)) {
                return true;
            }
            FALLTHROUGH;
        case TEXT_STATE_PAUSE_MENU:
            curItemAction = ref_func_80123810(play);

            if (curItemAction == PLAYER_IA_NONE) {
                return true;
            } else if (curItemAction < 0) {
                skip = SCRIPT_PACK_16(cmd->offsetContinueH, cmd->offsetContinueL);
            } else if (curItemAction == checkItemAction) {
                skip = SCRIPT_PACK_16(cmd->offsetEqualH, cmd->offsetEqualL);
            } else {
                skip = SCRIPT_PACK_16(cmd->offsetDefaultH, cmd->offsetDefaultL);
            }
            break;

        default:
            return true;
    }
    *script += skip;
    return false;
}
