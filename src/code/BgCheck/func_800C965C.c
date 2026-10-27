#include "types.h"

typedef struct {
    u8 pad[4];
    s32 data;
} CamFuncEntry;

typedef struct {
    u8 pad[0x20];
    CamFuncEntry *entries;
} CamFuncSource;

extern CamFuncSource *BgCheck_GetCollisionHeader(s32 a0, s32 a1);
extern s32 func_80100304(s32 data);

s32 BgCheck_GetBgCamFuncDataImpl(s32 a0, s32 index, s32 a2) {
    CamFuncSource *source = BgCheck_GetCollisionHeader(a0, a2);
    CamFuncEntry *entries;

    if (source == NULL) {
        return 0;
    }
    entries = source->entries;
    if (entries == NULL) {
        return 0;
    }
    return func_80100304(entries[index].data);
}
