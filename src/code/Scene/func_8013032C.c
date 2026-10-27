#include "types.h"

typedef struct {
    /* 0x00 */ u8 code;
    /* 0x01 */ u8 data1;
    /* 0x02 */ u8 pad2[2];
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ u8 unk6;
} SceneCmd;

typedef struct {
    /* 0x00000 */ u8 pad0[0x1701B];
    /* 0x1701B */ u8 unk1701B;
    /* 0x1701C */ u8 unk1701C;
    /* 0x1701D */ u8 pad1701D[5];
    /* 0x17022 */ u8 unk17022;
    /* 0x17023 */ u8 pad17023[0x18874 - 0x17023];
    /* 0x18874 */ u8 unk18874;
} PlayState;

void Scene_LoadAreaTextures(PlayState *play, u8 arg1);

void Scene_CommandSkyboxSettings(PlayState *play, SceneCmd *cmd) {
    play->unk18874 = cmd->unk4 & 3;
    play->unk1701B = play->unk1701C = cmd->unk5;
    play->unk17022 = cmd->unk6;
    Scene_LoadAreaTextures(play, cmd->data1);
}
