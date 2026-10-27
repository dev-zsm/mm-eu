#include "types.h"

typedef struct {
    s32 info[2];
    s32 rest[8];
} ColliderElement;

extern ColliderElement D_801BAD9C;
s32 Collider_InitElementDamageInfoAT(void *play, void *info);
s32 Collider_InitElementDamageInfoAC(void *play, void *rest);

s32 Collider_InitElement(void *play, ColliderElement *elem) {
    *elem = D_801BAD9C;
    Collider_InitElementDamageInfoAT(play, elem);
    Collider_InitElementDamageInfoAC(play, elem->rest);
    return 1;
}
