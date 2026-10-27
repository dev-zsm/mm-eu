#include "types.h"

typedef struct { u8 pad0[0x138C]; u16 flags[50]; } Flags;

extern void *DynaPoly_GetActor(void *, s32);
extern void DynaPolyActor_UnsetAllInteractFlags(void *);

void DynaPoly_UnsetAllInteractFlags(u8 *dyna, Flags *f, void *actor) {
    s32 i;
    void *a;

    for (i = 0; i < 50; i++) {
        if (f->flags[i] & 1) {
            a = DynaPoly_GetActor(dyna + 0x830, i);
            if (a != 0 && a == actor) {
                DynaPolyActor_UnsetAllInteractFlags(actor);
                return;
            }
        }
    }
}
