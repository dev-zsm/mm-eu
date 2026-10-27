#include "types.h"

typedef struct {
    u8 code;
    u8 pad1[7];
} SceneCmd;

typedef void (*SceneCmdHandler)(void *play, SceneCmd *cmd);

extern SceneCmdHandler D_801C3368[];

s32 Scene_ExecuteCommands(void *play, SceneCmd *sceneCmd) {
    u32 cmdCode;

    while (1) {
        cmdCode = sceneCmd->code;
        if (cmdCode == 0x14) {
            break;
        }
        if (cmdCode < 0x1F) {
            D_801C3368[cmdCode](play, sceneCmd);
        }
        sceneCmd++;
    }
    return 0;
}
