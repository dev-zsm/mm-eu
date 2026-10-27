#include "types.h"
typedef struct { u8 pad0[0x18]; s32 count; u8 *elems; } T;
void CollisionCheck_ApplyDamage(s32, s32, void *, u8 *);

void CollisionCheck_ApplyDamageJntSph(s32 a0, s32 a1, void *a2) {
    T *p = a2;
    s32 i;

    if (p->count > 0 && p->elems != 0) {
        for (i = 0; i < p->count; i++) {
            CollisionCheck_ApplyDamage(a0, a1, a2, p->elems + i * 0x40);
        }
    }
}
