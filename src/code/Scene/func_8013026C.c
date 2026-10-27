#include "types.h"

typedef struct {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 pad2[2];
    /* 0x4 */ s32 unk4;
} SceneCmd;

typedef struct {
    /* 0x00000 */ u8 pad0[0x170BC];
    /* 0x170BC */ u8 unk170BC;
    /* 0x170BD */ u8 pad170BD[3];
    /* 0x170C0 */ s32 unk170C0;
} PlayState;

extern s32 func_80100304(s32 arg0);

void Scene_CommandEnvLightSettings(PlayState *play, SceneCmd *cmd) {
    play->unk170BC = cmd->unk1;
    play->unk170C0 = func_80100304(cmd->unk4);
}
