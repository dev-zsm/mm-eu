#include "types.h"

extern s16 Quake_Request(void *camera, u32 type);
extern void Quake_SetSpeed(s16 index, s16 speed);
extern void Quake_SetPerturbations(s16 index, s16 y, s16 x, s16 fov, s16 roll);
extern void Quake_SetDuration(s16 index, s16 duration);

void Actor_RequestQuake(u8 *play, s16 verticalMag, s16 duration) {
    s16 index = Quake_Request(play + 0x220, 3);

    Quake_SetSpeed(index, 0x4E20);
    Quake_SetPerturbations(index, verticalMag, 0, 0, 0);
    Quake_SetDuration(index, duration);
}
