#include "types.h"

typedef struct { u8 pad0[0x15]; u8 flags; } OcCol;
typedef struct { u8 pad0[0xE]; u8 unkE[8]; u8 flags; u8 pad17[5]; s32 unk1C; u8 pad20[4]; OcCol *unk24; u8 pad28[0x34]; } TrisElem;
typedef struct { u8 pad0[0x18]; s32 count; TrisElem *elements; } Tris;
void Math_Vec3s_ToVec3f(void *a, void *b);
void CollisionCheck_HitEffects(s32 play, s32 a, OcCol *b, Tris *c, TrisElem *d, void *e);

void CollisionCheck_SetTrisHitFX(s32 play, s32 unused, Tris *tris) {
    TrisElem *el;
    f32 sp24[3];

    for (el = tris->elements; el < tris->elements + tris->count; el++) {
        if ((el->flags & 0x80) && el->unk24 != NULL && !(el->unk24->flags & 0x40)) {
            Math_Vec3s_ToVec3f(sp24, el->unkE);
            CollisionCheck_HitEffects(play, el->unk1C, el->unk24, tris, el, sp24);
            el->unk24->flags |= 0x40;
            return;
        }
    }
}
