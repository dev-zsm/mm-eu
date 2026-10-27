#include "types.h"
typedef struct { u8 pad0[0x11]; u8 f11; u8 pad1[3]; u8 f15; } AC;
typedef struct { u8 pad[0xCC]; s32 count; AC *list[1]; } CC;
extern void (*D_801BAFD0[])(s32, CC *, AC *);
void CollisionCheck_Damage(s32 a0, CC *a1) {
    s32 i;
    for (i = 0; i < a1->count; i++) {
        AC *ac = a1->list[i];
        if (ac == 0) continue;
        if (ac->f11 & 0x40) continue;
        D_801BAFD0[ac->f15](a0, a1, ac);
    }
}
