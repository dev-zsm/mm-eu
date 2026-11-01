// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x15];
    u8 flags15;
} Hit;

typedef struct {
    u8 pad0[0xE];
    u8 pos[8];
    u8 flags16;
    u8 pad17[5];
    s32 unk1C;
    u8 pad20[4];
    Hit *hit;
    u8 pad28[0x18];
} Elem;

typedef struct {
    u8 pad0[0x18];
    s32 count;
    Elem *elems;
} Col;

extern void Math_Vec3s_ToVec3f(void *out, void *pos, Col *col);
extern void CollisionCheck_HitEffects(s32 play, s32 a, Hit *h, Col *col, Elem *e, void *out);

void CollisionCheck_SetJntSphHitFX(s32 play, s32 unused, Col *col) {
    Elem *e;
    Col *jnt = col;
    u8 sp24[12];

    for (e = jnt->elems; e < jnt->elems + jnt->count; e++) {
        if ((e->flags16 & 0x80) && e->hit != NULL && !(e->hit->flags15 & 0x40)) {
            Math_Vec3s_ToVec3f(sp24, e->pos, col);
            CollisionCheck_HitEffects(play, e->unk1C, e->hit, jnt, e, sp24);
            e->hit->flags15 |= 0x40;
            return;
        }
    }
}
