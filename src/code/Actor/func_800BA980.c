#include "types.h"

typedef struct {
    u8 pad0[0x10];
    void *overlay;
    u8 pad14[8];
    u16 flags;
    s8 numLoaded;
} OverlayActor;

extern void ZeldaArena_Free(void *overlay, OverlayActor *actor);

void Actor_FreeOverlay(OverlayActor *actor) {
    if (actor->numLoaded == 0) {
        if (actor->overlay != NULL) {
            if (!(actor->flags & 2)) {
                if (actor->flags & 1) {
                    actor->overlay = NULL;
                } else {
                    ZeldaArena_Free(actor->overlay, actor);
                    actor->overlay = NULL;
                }
            }
        }
    }
}
