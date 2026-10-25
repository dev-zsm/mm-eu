#include "types.h"

typedef struct {
    u8 pad0[0x32];
    s16 yaw;
    u8 pad34[0x30];
    f32 velocityX;
    f32 velocityY;
    f32 velocityZ;
    f32 speedXZ;
    f32 gravity;
    f32 minVelocityY;
} Actor;

extern f32 Math_CosS(s16 angle);
extern f32 Math_SinS(s16 angle);

void Actor_UpdateVelocityWithGravity(Actor *actor) {
    actor->velocityX = Math_SinS(actor->yaw) * actor->speedXZ;
    actor->velocityZ = Math_CosS(actor->yaw) * actor->speedXZ;
    actor->velocityY += actor->gravity;
    if (actor->velocityY < actor->minVelocityY) {
        actor->velocityY = actor->minVelocityY;
    }
}
