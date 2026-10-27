#include "types.h"

typedef struct { s16 id; s16 pad; void *ptr; } Entry;

void *Actor_FindSharedMemoryEntry(u8 *play, s16 id) {
    Entry *e = (Entry *)(play + 0x1EAC);
    s32 i;

    for (i = 0; i < 8; i++) {
        if (id == e->id) {
            return e->ptr;
        }
        e++;
    }
    return 0;
}
