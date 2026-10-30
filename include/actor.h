#ifndef ACTOR_H
#define ACTOR_H

#include "types.h"

/* Every actor instance starts with this block, and the fields of one actor type follow it. The layout is not known yet:
 * 0x144 bytes is the smallest instance size found in the actor profiles of the ROM (tools/sig_actors.py). */
typedef struct Actor {
    /* 0x000 */ u8 unk0[0x144];
} Actor;

typedef struct GraphicsContext GraphicsContext;

/* Passed to every actor handler. Only the first field is known (the graphics calls of the actors read it first); the size and the
 * rest of the layout are not, so neither sizeof nor pointer arithmetic on it means anything yet. */
typedef struct PlayState {
    /* 0x00 */ GraphicsContext *gfxCtx;
} PlayState;

typedef void (*ActorFunc)(Actor *thisx, PlayState *play);

#endif
