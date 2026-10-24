#include "types.h"
s32 Play_GetCamera(s32, s16);
void Camera_ChangeSetting(s32, s16);
void func_8016AC30(s32 a0, s16 a1, s16 a2) {
    Camera_ChangeSetting(Play_GetCamera(a0, a1), a2);
}
