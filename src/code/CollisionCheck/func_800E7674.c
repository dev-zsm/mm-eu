// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x18];
    s32 count;
    s32 base;
} CollisionTriSet;

void CollisionCheck_ApplyDamage(s32, s32, CollisionTriSet *, s32);

void CollisionCheck_ApplyDamageTris(s32 arg0, s32 arg1, CollisionTriSet *arg2) {
    CollisionTriSet *p;
    s32 i;
    s32 off;

    p = arg2;
    i = 0;
    off = 0;
    if (p->count > 0) {
        do {
            CollisionCheck_ApplyDamage(arg0, arg1, arg2, arg2->base + off);
            i += 1;
            off += 0x5C;
        } while (i < p->count);
    }
}
