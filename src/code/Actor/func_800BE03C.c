#include "types.h"

typedef struct { u32 type; } Hit;
typedef struct { u8 pad0[0x24]; Hit *hit; u8 pad28[0x18]; } Elem;
typedef struct { u8 pad0[0x18]; s32 count; Elem *elements; } Sph;
typedef struct { u8 pad0[0x11E]; u8 dropFlag; } Act;

void Actor_SetDropFlagJntSph(Act *actor, Sph *sph) {
    s32 i;
    Hit *h;
    Elem *e;
    u8 flag;

    actor->dropFlag = 0;
    for (i = sph->count - 1; i >= 0; i--) {
        e = &sph->elements[i];
        h = e->hit;
        if (h == NULL) {
            flag = 0;
        } else if (h->type & 0x800) {
            flag = 1;
        } else if (h->type & 0x1000) {
            flag = 2;
        } else if (h->type & 0x2000) {
            flag = 0x20;
        } else {
            flag = 0;
        }
        actor->dropFlag |= flag;
    }
}
