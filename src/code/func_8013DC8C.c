#include "types.h"

extern s32 Object_IsLoaded(void *objectCtx, s8 objectId);

s8 SubS_IsObjectLoaded(s8 objectId, void *play) {
    s32 loaded;

    if (!Object_IsLoaded((u8 *)play + 0x17D88, objectId)) {
        loaded = 0;
    } else {
        loaded = 1;
    }
    return loaded;
}
