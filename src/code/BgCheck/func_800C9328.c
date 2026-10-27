#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ void *unk4;
    /* 0x08 */ void *unk8;
    /* 0x0C */ u8 pad[0x58];
} Ent; /* size 0x64 */

typedef struct {
    /* 0x0000 */ Ent ents[50];
    /* 0x1388 */ u8 pad1388[4];
    /* 0x138C */ u16 flags[50];
} Tbl;

void Actor_SetObjectDependency(void *a, void *b);
void CollisionHeader_SegmentedToVirtual(void *a);

void BgCheck_InitCollisionHeaders(void *a0, void *a1) {
    Tbl *t = (Tbl *)((u8 *)a0 + 0x50);
    s32 i;
    Ent *e;

    for (i = 0; i < 0x32; i++) {
        u16 f = t->flags[i];
        if ((f & 1) && !(f & 2)) {
            e = &t->ents[i];
            Actor_SetObjectDependency(a1, e->unk4);
            CollisionHeader_SegmentedToVirtual(e->unk8);
        }
    }
}
