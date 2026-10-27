#include "types.h"
typedef struct { u8 pad[0x15]; u8 unk15; } Other;
typedef struct { u8 pad[0x2E]; u8 unk2E; u8 pad2F[5]; s32 unk34; u8 pad38[4]; Other *unk3C; } Col;
void Math_Vec3s_ToVec3f(void *, void *);
void CollisionCheck_HitEffects(void *, s32, void *, void *, void *, void *);
void CollisionCheck_SetCylHitFX(void *play, void *unused, Col *col) {
    u8 sp28[0x10];
    if (col->unk2E & 0x80) {
        if (col->unk3C != NULL && !(col->unk3C->unk15 & 0x40)) {
            Math_Vec3s_ToVec3f(sp28, (u8 *)col + 0x26);
            CollisionCheck_HitEffects(play, col->unk34, col->unk3C, col, (u8 *)col + 0x18, sp28);
            col->unk3C->unk15 |= 0x40;
        }
    }
}
