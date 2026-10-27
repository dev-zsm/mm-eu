// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void Camera_ChangeModeFlags(s32 a0, s32 a1, s32 a2);
void Camera_ChangeMode(s32 a0, s16 a1) {
    Camera_ChangeModeFlags(a0, a1, 0);
}
