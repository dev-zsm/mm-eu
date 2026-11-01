#include "types.h"

typedef struct {
    u8 pad0[0xB];
    u8 unkB;
    u8 padC;
    u8 unkD;
    u8 padE[2];
} SceneEntry;

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
    u8 unkA6;
    u8 padA7[0xB0 - 0xA7];
    s32 unkB0;
    u8 padB4[0x18E54 - 0xB4];
    SceneEntry* unk18E54;
} Play;

extern SceneEntry D_801C4960[];
extern s32 D_801EFA08;

extern s32 Play_LoadFile(SceneEntry* entry);
extern void Play_InitScene(Play* play, s32 a1);
extern void Room_SetupFirstRoom(Play* play, void* p);

void Play_SpawnScene(Play* play, s32 sceneId, s32 spawn) {
    SceneEntry* scene = &D_801C4960[sceneId];

    scene->unkD = 0;
    play->unk18E54 = scene;
    play->unkA4 = sceneId;
    play->unkA6 = scene->unkB;
    play->unkB0 = Play_LoadFile(scene);
    scene->unkD = 0;
    D_801EFA08 = play->unkB0 + 0x80000000;
    Play_InitScene(play, spawn);
    Room_SetupFirstRoom(play, (u8*)play + 0x186E0);
}
