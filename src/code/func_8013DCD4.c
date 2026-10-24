#include "types.h"

extern s32 Object_GetSlot(void *objectCtx, s16 objectId);

s8 SubS_GetObjectSlot(s16 objectId, u8 *play) {
    return Object_GetSlot(play + 0x17D88, objectId);
}
