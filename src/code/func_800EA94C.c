#include "types.h"

typedef struct {
    u16 id;
    u16 frame;
} CsCmdLight;

typedef struct {
    u8 pad0[0x10];
    u16 frame;
} CsState;

typedef struct {
    u8 pad0[0x170C7];
    u8 lightSetting;
    u8 pad170C8[0x170E0 - 0x170C8];
    f32 lightBlend;
} PlayState;

void CutsceneCmd_SetLightSetting(PlayState *play, CsState *cs, CsCmdLight *cmd) {
    if (cs->frame == cmd->frame) {
        if (cmd->id != 0x20) {
            play->lightSetting = cmd->id - 1;
            play->lightBlend = 1.0f;
            return;
        }
        play->lightSetting = 0xFF;
    }
}
