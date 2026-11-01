// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"
void Camera_ChangeMode(s32 a0, s16 a1) {
    Camera_ChangeModeFlags(a0, a1, 0);
}
