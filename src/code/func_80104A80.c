#include "types.h"

typedef struct {
    u8 pad0[0x20];
    u32 flags;
} MapDispState;
extern MapDispState D_801BF708;
s32 Object_GetSlot(void *objectCtx, s32 id);
s32 Object_IsLoaded(void *objectCtx, s32 id);
void MapDisp_AwaitGameplayDangeonKeep(u8 *play) {
    u8 *objectCtx;
    register s32 objectIndex;
    objectCtx = play + 0x17D88;
    objectIndex = Object_GetSlot(objectCtx, 3);
    if (objectIndex < 0) {
        D_801BF708.flags |= 1;
    } else
        if (1) {
        do {
        }
        while (Object_IsLoaded(objectCtx, objectIndex) == 0);
    }
}
