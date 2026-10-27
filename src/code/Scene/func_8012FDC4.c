#include "types.h"

typedef struct {
    u8 pad0[0x18848];
    u8 unk18848;
    u8 pad18849[3];
    s32 unk1884C;
} PlayState;

typedef struct {
    u8 pad0[1];
    u8 unk1;
    u8 pad2[2];
    s32 unk4;
} SceneCmd;

extern s32 func_80100304(s32 arg);

void Scene_CommandRoomList(PlayState *play, SceneCmd *cmd) {
    play->unk18848 = cmd->unk1;
    play->unk1884C = func_80100304(cmd->unk4);
}
