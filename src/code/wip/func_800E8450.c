#include "types.h"
typedef struct { f32 x, y, z; } Vec;
extern u8 D_801BB038[];
extern s16 D_801BB03A[3];
extern s16 D_801BB066[3];
void Effect_Add(s32, void *, s32, s32, s32, void *);
void Audio_PlaySfx_AtPos(s32, s32);
void CollisionCheck_SpawnShieldParticlesWood(s32 a0, Vec *pos, s32 sfx) {
    s32 sp24;
    s32 x = pos->x;
    s32 y;
    s32 z;
    D_801BB03A[0] = x;
    y = pos->y;
    D_801BB03A[1] = y;
    z = pos->z;
    D_801BB03A[2] = z;
    D_801BB066[0] = x;
    D_801BB066[1] = y;
    D_801BB066[2] = z;
    Effect_Add(a0, &sp24, 3, 0, 1, D_801BB038);
    Audio_PlaySfx_AtPos(sfx, 0x1837);
}
