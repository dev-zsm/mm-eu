#include "types.h"
typedef struct { s16 id; s8 flag; void *ptr; } Entry;
extern void *ZeldaArena_Malloc(s32 a);
void *Actor_AddSharedMemoryEntry(u8 *ctx, s16 id, void *ptr, s32 size) {
    Entry *e = (Entry *)(ctx + 0x1EAC);
    s32 i;
    for (i = 0; i < 8; i++, e++) {
        if (e->id == 0) {
            if (ptr == 0) {
                ptr = ZeldaArena_Malloc(size);
                if (ptr == 0) {
                    return 0;
                }
                e->flag = 1;
            }
            e->id = id;
            e->ptr = ptr;
            return ptr;
        }
    }
    return 0;
}
