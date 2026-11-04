// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_msgevent.h"

s32 MsgEvent_Autotalk(Actor* actor, PlayState* play, u8** script, MsgScriptCallback callback, s32* endScript) {
    MsgScriptCmdAutotalk* cmd = (MsgScriptCmdAutotalk*)*script;
    f32 xzRange = actor->xzDistToPlayer + 1.0f;
    f32 yRange = fabsf(actor->playerHeightRel) + 1.0f;
    f32 xzDist;
    s16 skip = SCRIPT_PACK_16(cmd->offsetH, cmd->offsetL);

    if (Actor_TalkOfferAccepted(actor, &play->state)) {
        *script += skip;
    } else {
        actor->flags |= ACTOR_FLAG_TALK_OFFER_AUTO_ACCEPTED;
        xzDist = actor->xzDistToPlayer;
        actor->xzDistToPlayer = 0.0f;
        Actor_OfferTalkExchange(actor, play, xzRange, yRange, PLAYER_IA_NONE);
        actor->xzDistToPlayer = xzDist;
        return true;
    }
    return false;
}
