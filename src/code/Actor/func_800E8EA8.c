// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/code_800E8EA0.h"

s32 Actor_TrackPlayerSetFocusHeight(PlayState* play, Actor* actor, Vec3s* headRot, Vec3s* torsoRot, f32 focusHeight) {
    Player* player = GET_PLAYER(play);
    s16 yaw;
    Vec3f target;

    actor->focus.pos = actor->world.pos;
    actor->focus.pos.y += focusHeight;

    if (!((play->csCtx.state != CS_STATE_IDLE) || gDbgCamEnabled)) {
        yaw = ABS_ALT(BINANG_SUB(actor->yawTowardsPlayer, actor->shape.rot.y));
        if (yaw >= 0x4300) {
            Actor_TrackNone(headRot, torsoRot);
            return false;
        }
    }

    if ((play->csCtx.state != CS_STATE_IDLE) || gDbgCamEnabled) {
        target = play->view.eye;
    } else {
        target = player->actor.focus.pos;
    }

    Actor_TrackPoint(actor, &target, headRot, torsoRot);

    return true;
}
