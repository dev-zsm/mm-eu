#include "types.h"

extern void Math_Vec3f_Yaw(s32, s32, s32);

void Actor_WorldYawTowardPoint(s32 arg0, s32 arg1) {
    Math_Vec3f_Yaw(arg0 + 0x24, arg1, arg0);
}
