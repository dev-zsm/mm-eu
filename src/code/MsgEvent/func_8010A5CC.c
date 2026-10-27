#include "types.h"

typedef struct {
    u8 pad0[0x14B];
    u8 unk14B;
} Player;
typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} PlayState;
s32 MsgEvent_CheckGoron(void *arg0, PlayState *play, u8 **script, s32 arg3) {
    Player *player = play->player;
    u8 *cmd = *script;
    u8 **new_var;
    s16 offset = (*script)[2] | (cmd[1] << 8);
    if (player->unk14B == 1) {
        new_var = script;
        *new_var = (*new_var) + offset;
    }
    return 0;
}
