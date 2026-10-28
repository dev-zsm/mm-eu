#include "types.h"

typedef struct {
    u8 pad[0x5C];
} Elem;
typedef struct {
    u8 pad0[0x18];
    s32 count;
    Elem *elem;
} Col;
extern void Collider_ResetOCBase(void *ctx, Col *c);
extern void Collider_ResetTrisElementOC(void *ctx, Elem *e);
s32 Collider_ResetTrisOC(void *ctx, Col *c) {
    Col *new_var;
    Elem *e;
    new_var = c;
    Collider_ResetOCBase(ctx, c);
    for (e = new_var->elem; e < (new_var->elem + new_var->count); e++) {
        Collider_ResetTrisElementOC(ctx, e);
    }

    return 1;
}
