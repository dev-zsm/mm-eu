// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad0[0x46];
    s16 posX; /* 0x46 */
    s16 posY; /* 0x48 */
    s16 posZ; /* 0x4A */
} ColliderCylinder;

typedef struct {
    u8 pad0[0x24];
    Vec3f worldPos; /* 0x24 */
    u8 pad30[0x194 - 0x30];
    ColliderCylinder collider; /* 0x194 */
} EnHy;

typedef struct {
    u8 pad0[0x18884];
    u8 colChkCtx[1]; /* 0x18884 */
} PlayState;

s32 CollisionCheck_SetAC(PlayState *play, void *colChkCtx, void *collider);
s32 CollisionCheck_SetOC(PlayState *play, void *colChkCtx, void *collider);

void EnHy_UpdateCollider(EnHy *this, PlayState *play) {
    this->collider.posX = this->worldPos.x;
    this->collider.posY = this->worldPos.y;
    this->collider.posZ = this->worldPos.z;
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider);
}
