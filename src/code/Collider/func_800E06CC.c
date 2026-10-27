#include "types.h"

typedef struct {
    char pad0[0xE];
    s16 unkE;
    s16 unk10;
    s16 unk12;
    char pad14[2];
    u8 flags;
    char pad17[5];
    u32 unk1C;
    char pad20[4];
    u32 unk24;
} ColliderElement;

void Collider_ResetACElement(void *arg0, ColliderElement *elem) {
    elem->unk12 = 0;
    elem->flags &= ~2;
    elem->flags &= ~0x80;
    elem->unk1C = 0;
    elem->unk24 = 0;
    elem->unk10 = elem->unk12;
    elem->unkE = elem->unk12;
}
