#include "types.h"

typedef struct { u8 pad[0x40]; } Elem;
typedef struct { u8 pad0[0x18]; s32 count; Elem *elem; } Col;

extern void Collider_DestroyBase(void *ctx, Col *c);
extern void Collider_DestroyJntSphElement(void *ctx, Elem *e);

s32 Collider_DestroyJntSph(void *ctx, Col *c) {
    Elem *e;

    Collider_DestroyBase(ctx, c);
    for (e = c->elem; e < c->elem + c->count; e++) {
        Collider_DestroyJntSphElement(ctx, e);
    }
    c->count = 0;
    c->elem = 0;
    return 1;
}
