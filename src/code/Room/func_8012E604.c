#include "types.h"

typedef struct {
    u8 pad0[0xE];
    s16 unkE;
} RoomRet;
typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 pad3[0x19];
} BgEntry;
typedef struct {
    u8 pad0[8];
    u8 count;
    u8 pad9[3];
    s32 unkC;
} Room;
typedef struct {
    u8 pad0[0x148];
    s16 unk148;
} RoomSrc;
typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
} Dest;
typedef struct {
    u8 pad0[0x800];
    RoomSrc *rooms[1];
    u8 pad804[0xC];
    s16 unk810;
    u8 pad812[0x1E];
    u8 unk830[0x149C];
    Dest *unk1CCC;
} Play;
RoomRet *BgCheck_GetBgCamFuncDataImpl(void *a, s32 b, s32 c);
BgEntry *func_80100304(s32 a);
void func_800862F0(void *a, s32 b);
extern u8 D_801D6030[];
BgEntry *Room_GetImageMultiBgEntry(Room *room, Play *play) {
    s32 i;
    s32 id;
    BgEntry *entry;
    s16 v;
    RoomSrc *new_var;
    new_var = play->rooms[play->unk810];
    id = new_var->unk148;
    v = BgCheck_GetBgCamFuncDataImpl(play->unk830, id, 0x32)->unkE;
    if (v >= 0) {
        id = v;
    }
    play->unk1CCC->unk1C = (play->unk1CCC->unk1C & 0xFF00) | id;
    entry = func_80100304(room->unkC);
    for (i = 0; i < room->count; i++, entry++) {
        if (id == entry->unk2) {
            return entry;
        }
    }

    func_800862F0(D_801D6030, 0x351);
    return (void *) 0;
}
