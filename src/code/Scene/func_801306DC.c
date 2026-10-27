#include "types.h"

typedef struct {
    u8 pad0[4];
    s8 unk4;
    s8 unk5;
    s8 unk6;
    u8 unk7;
} WindCommand;

typedef struct {
    u8 pad0[0x170B0];
    s16 unk170B0;
    s16 unk170B2;
    s16 unk170B4;
    u8 pad170B6[2];
    f32 unk170B8;
} WindSettings;

void Scene_CommandWindSettings(WindSettings *play, WindCommand *cmd) {
    s8 x = cmd->unk4;
    s8 y = cmd->unk5;
    s8 z = cmd->unk6;

    play->unk170B0 = x;
    play->unk170B2 = y;
    play->unk170B4 = z;
    play->unk170B8 = cmd->unk7;
}
