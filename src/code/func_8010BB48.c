#include "types.h"

typedef struct {
    u8 pad0[0x116];
    u16 unk116;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player* player;
} PlayState;

extern void func_80147CC4(PlayState* play);

s32 MsgEvent_PlayerTalk(s32 arg0, PlayState* play, u8** script, s32 arg3) {
    u8* cmd = *script;
    Player* player = play->player;
    u16 id = cmd[2] | (cmd[1] << 8);

    player->unk116 = id;
    func_80147CC4(play);
    return 0;
}
