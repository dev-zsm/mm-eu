// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_OfferItem(Actor* actor, PlayState* play, u8** script, MsgScriptCallback callback, s32* endScript) {
    MsgScriptCmdOfferItem* cmd = (MsgScriptCmdOfferItem*)*script;
    s32 getItemId = SCRIPT_PACK_16(cmd->itemIdH, cmd->itemIdL);
    f32 xzRange = actor->xzDistToPlayer + 1.0f;
    f32 yRange = fabsf(actor->playerHeightRel) + 1.0f;
    s16 skip = SCRIPT_PACK_16(cmd->offsetH, cmd->offsetL);

    if (Actor_HasParent(actor, play)) {
        *script += skip;
    } else {
        Actor_OfferGetItem(actor, play, getItemId, xzRange, yRange);
        return true;
    }
    return false;
}
