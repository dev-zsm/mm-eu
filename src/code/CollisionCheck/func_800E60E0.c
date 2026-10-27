#include "types.h"

typedef struct {
    u8 pad0[0x15];
    u8 flags;
} Elem;

typedef struct {
    u8 pad0[0x18];
    u8 pos18[0xE];
    u8 flags26[8];
    u8 unk2E;
    u8 pad2F[5];
    s32 unk34;
    s32 pad38;
    Elem *elem;
} Quad;

void Math_Vec3s_ToVec3f(void *out, void *a);
void CollisionCheck_HitEffects(s32 ctx, s32 a, Elem *e, Quad *q, void *p, void *v);

void CollisionCheck_SetQuadHitFX(s32 ctx, s32 unused, Quad *q) {
    u8 sp28[16];

    if (q->unk2E & 0x80) {
        if (q->elem != NULL && !(q->elem->flags & 0x40)) {
            Math_Vec3s_ToVec3f(sp28, q->flags26);
            CollisionCheck_HitEffects(ctx, q->unk34, q->elem, q, q->pos18, sp28);
            q->elem->flags |= 0x40;
        }
    }
}
