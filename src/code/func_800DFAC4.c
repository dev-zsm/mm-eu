#include "types.h"

extern s16 Quake_Request(void *camera, s32 type);
extern void Quake_SetSpeed(s16 index, s16 speed);
extern void Quake_SetPerturbations(s16 index, s16 y, s16 x, s16 fov, void *camShake);
extern void Quake_SetDuration(s16 index, s16 duration);

s32 Camera_AddQuake(void *camera, s32 arg1, s16 y, s16 duration) {
    s16 index;

    index = Quake_Request(camera, 3);
    if (index == 0) {
        return 0;
    }
    Quake_SetSpeed(index, 0x61A8);
    Quake_SetPerturbations(index, y, 0, 0, NULL);
    Quake_SetDuration(index, duration);
    return 1;
}
