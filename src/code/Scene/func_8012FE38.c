#include "types.h"

typedef struct {
    u32 segment;
    u8 pad4[0x40];
} ObjEntry;

typedef struct {
    u8 pad0[0x17D88];
    u8 objCtx[0xB];
    u8 subKeepIndex;
    u8 pad17D94[4];
    ObjEntry status[1];
} PlayState;

typedef struct {
    u8 pad0[1];
    u8 unk1;
    u8 pad2[2];
    s32 unk4;
} SceneCmd;

s32 func_8012F680(void *a0, s16 a1);
s32 Play_LoadFile(void *a0, void *a1);
extern u8 D_801C3310[];
extern u32 D_801EFA14;

void Scene_CommandSpecialFiles(PlayState *play, SceneCmd *cmd) {
    if (cmd->unk4 != 0) {
        play->subKeepIndex = func_8012F680(play->objCtx, cmd->unk4);
        D_801EFA14 = play->status[play->subKeepIndex].segment + 0x80000000;
    }
    if (cmd->unk1 != 0) {
        *(s32 *)((u8 *)play + 0x18868) = Play_LoadFile(play, &D_801C3310[cmd->unk1 * 8 - 8]);
    }
}
