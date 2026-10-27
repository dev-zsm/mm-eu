#include "types.h"

typedef struct {
    u8 pad0[0x1B0]; u8 mode; u8 flags; u8 pad1B2[2];
    void (*fn)();
    s32 arg0; s32 arg1;
} Task;

void func_80186500(Task *t) {
    t->flags |= 2;
    switch (t->mode) {
        case 0:
            t->fn();
            break;
        case 1:
            t->fn(t->arg0);
            break;
        case 2:
            t->fn(t->arg0, t->arg1);
            break;
    }
    t->flags |= 1;
}
