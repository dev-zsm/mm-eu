#include "types.h"

typedef struct {
    /* 0x0 */ s16 id;
    /* 0x2 */ s8 allocated;
    /* 0x4 */ void *data;
} SharedMemoryEntry;

typedef struct {
    /* 0x0000 */ u8 pad0[0x1EAC];
    /* 0x1EAC */ SharedMemoryEntry entries[8];
} ActorContext;

extern void ZeldaArena_Free(void *data);

void *Actor_FreeSharedMemoryEntry(ActorContext *ctx, s16 id) {
    SharedMemoryEntry *entry = ctx->entries;
    s32 i;

    for (i = 0; i < 8; i++, entry++) {
        if (id == entry->id) {
            entry->id = 0;
            if (entry->allocated) {
                ZeldaArena_Free(entry->data);
                entry->allocated = 0;
            }
            return entry->data;
        }
    }
    return NULL;
}
