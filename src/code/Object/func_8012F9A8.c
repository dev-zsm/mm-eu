#include "types.h"

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad2[0x44 - 0x2];
} ObjectEntry; // size = 0x44

typedef struct {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ u8 count;
    /* 0x09 */ u8 pad9[3];
    /* 0x0C */ ObjectEntry slots[1];
} ObjectContext;

s32 Object_GetSlot(ObjectContext *objectCtx, s16 id) {
    s32 i;

    for (i = 0; i < objectCtx->count; i++) {
        s16 entryId = objectCtx->slots[i].id;

        if (((entryId < 0) ? -entryId : entryId) == id) {
            return i;
        }
    }
    return -1;
}
