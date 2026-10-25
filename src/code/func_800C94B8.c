#include "types.h"

typedef struct {
    u16 setting;
    u16 pad2;
    u32 unk4;
} BgCamEntry;

typedef struct {
    u8 pad0[0x20];
    BgCamEntry* entries;
} BgCamData;

extern BgCamData* BgCheck_GetCollisionHeader(s32 a0, s32 a1);

u16 BgCheck_GetBgCamSettingImpl(s32 a0, s32 index, s32 a2) {
    BgCamData* data;
    BgCamEntry* entries;
    u16 setting;

    data = BgCheck_GetCollisionHeader(a0, a2);
    if (data == NULL) {
        return 0;
    }
    entries = data->entries;
    return setting = entries[index].setting;
}
