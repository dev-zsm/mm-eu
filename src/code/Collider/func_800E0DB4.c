// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad[0x40];
} Elem;
typedef struct {
    u8 pad0[0x18];
    s32 count;
    Elem *elems;
} Info;
void Collider_ResetACBase(void *ctx);
void func_800E08C4(void *ctx, Elem *elem);
s32 Collider_ResetJntSphAC(void *ctx, Info *info) {
    Info *new_var2;
    Elem *e;
    void *new_var;
    new_var2 = info;
    Collider_ResetACBase(ctx);
    for (e = new_var2->elems; e < (new_var2->elems + new_var2->count); e++) {
        new_var = ctx;
        func_800E08C4(new_var, e);
    }

    return 1;
}
