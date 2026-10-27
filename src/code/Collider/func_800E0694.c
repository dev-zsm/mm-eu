#include "types.h"

typedef struct {
    u8 pad0[0x15];
    u8 flags;
    u8 pad16[2];
    s32 unk18;
    u8 pad1C[4];
    s32 unk20;
} Element;

extern void Collider_ResetATElementUnk(s32 arg0, Element *elem);

void Collider_ResetATElement(s32 arg0, Element *elem) {
    elem->unk18 = 0;
    elem->unk20 = 0;
    elem->flags &= ~2;
    elem->flags &= ~0x40;
    Collider_ResetATElementUnk(arg0, elem);
}
