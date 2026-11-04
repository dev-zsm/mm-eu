// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/code_800E8EA0.h"

s32 Actor_TrackPoint(Actor* actor, Vec3f* target, Vec3s* headRot, Vec3s* torsoRot) {
    s16 targetPitch;
    s16 targetYaw;
    s16 yawDiff;

    targetPitch = Math_Vec3f_Pitch(&actor->focus.pos, target);
    targetYaw = Math_Vec3f_Yaw(&actor->focus.pos, target) - actor->world.rot.y;

    Math_SmoothStepToS(&headRot->x, targetPitch, 6, 0x7D0, 1);
    headRot->x = CLAMP(headRot->x, -0x1770, 0x1770);

    yawDiff = Math_SmoothStepToS(&headRot->y, targetYaw, 6, 0x7D0, 1);
    headRot->y = CLAMP(headRot->y, -0x1F40, 0x1F40);

    if ((yawDiff != 0) && (ABS_ALT(headRot->y) < 0x1F40)) {
        return false;
    }

    Math_SmoothStepToS(&torsoRot->y, targetYaw - headRot->y, 4, 0x7D0, 1);
    torsoRot->y = CLAMP(torsoRot->y, -0x2EE0, 0x2EE0);

    return true;
}
