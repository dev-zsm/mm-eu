#include "types.h"

extern void Math_Vec3f_Yaw(s32, s32, s32);

s16 Actor_WorldYawTowardPoint(struct Actor *actor, struct Vec3f *refPoint) {
    Math_Vec3f_Yaw((u8 *)actor + 0x24, refPoint, actor);
}
