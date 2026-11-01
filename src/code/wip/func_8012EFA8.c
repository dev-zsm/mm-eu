#include "types.h"
typedef struct { s8 unk0; u8 pad1[0x13]; s8 unk14; u8 pad15[0xB]; s32 unk20; } RoomCtx;
void func_800BA51C(void *, void *, void *);
void Actor_SpawnTransitionActors(void *, void *);
void Map_InitRoomData(void *, s32);
void Map_SetAreaEntrypoint(void *);
void Audio_SetEnvReverb(s32);
void Room_FinishRoomChange(u8 *play, RoomCtx *room) {
    s8 *q = &room->unk0;
    room->unk14 = -1;
    room->unk20 = 0;
    func_800BA51C(play, play + 0x1CA0, room);
    Actor_SpawnTransitionActors(play, play + 0x1CA0);
    if (*q >= 0) {
        Map_InitRoomData(play, *q);
        Map_SetAreaEntrypoint(play);
    }
    Audio_SetEnvReverb(*(s8 *)(play + 0x20000 - 0x791C));
}
