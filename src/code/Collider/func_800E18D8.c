#include "types.h"

typedef struct {
    u8 pad0[0x5C];
} Elem;
typedef struct {
    u8 pad0[0x18];
    s32 count;
    Elem *elem;
} Coll;
extern void Collider_ResetACBase(s32, Coll *);
extern void func_800E1448(s32, Elem *);
s32 Collider_ResetTrisAC(s32 a0, Coll *a1) {
    Elem *e;
    Coll *new_var;
    new_var = a1;
    Collider_ResetACBase(a0, a1);
    for (e = new_var->elem; e < (new_var->elem + new_var->count); e++) {
        func_800E1448(a0, e);
    }

    return 1;
}
