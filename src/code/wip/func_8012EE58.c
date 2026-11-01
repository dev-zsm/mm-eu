#include "types.h"

typedef struct {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ u8 pad1[0xB];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x21];
    /* 0x31 */ s8 unk31;
    /* 0x32 */ u8 pad32[2];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x20];
    /* 0x58 */ u8 unk58[1];
} Room;

typedef struct {
    /* 0x00000 */ u8 pad0[0xA4];
    /* 0x000A4 */ s16 unkA4;
    /* 0x000A6 */ u8 padA6[0x1C26];
    /* 0x01CCC */ void *unk1CCC;
    /* 0x01CD0 */ u8 pad1CD0[0x153F7];
    /* 0x170C7 */ u8 unk170C7;
    /* 0x170C8 */ u8 pad170C8[0x1C];
    /* 0x170E4 */ u8 unk170E4;
} Play;

extern s32 D_801EFA0C;
extern s32 func_80088070();
extern void Scene_ExecuteCommands();
extern void func_801235F0();
extern void Actor_SpawnTransitionActors();
extern void func_800FE8A8();
extern s32 Environment_GetStormState();
extern void Environment_StopStormNatureAmbience();

s32 Room_ProcessRoomRequest(Play *play, Room *room) {
    s32 v;

    if (room->unk31 != 1) {
        return 1;
    }
    if (func_80088070(room->unk58, 0, 0) != 0) {
        return 0;
    }
    v = room->unk34;
    room->unk31 = 0;
    room->unkC = v;
    D_801EFA0C = v + 0x80000000;
    Scene_ExecuteCommands(play, room->unkC);
    func_801235F0(play, play->unk1CCC);
    Actor_SpawnTransitionActors(play, (u8 *)play + 0x1CA0);
    if ((play->unkA4 != 0x13 || room->unk0 != 1) && play->unkA4 != 0x56) {
        play->unk170C7 = 0xFF;
        play->unk170E4 = 0;
    }
    func_800FE8A8();
    if (Environment_GetStormState(play) == 0) {
        Environment_StopStormNatureAmbience(play);
    }
    return 1;
}
