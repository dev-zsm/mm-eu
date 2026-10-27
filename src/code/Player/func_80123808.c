#include "types.h"

typedef struct {
    u8 pad0[0x394];
    u8 unk394;
    u8 pad395[0xA6C - 0x395];
    u32 stateFlags1;
    u32 stateFlags2;
    u32 stateFlags3;
} Player;

typedef struct {
    u8 pad0[0x1F08];
    u8 unk1F08;
    u8 pad1F09[0x18875 - 0x1F09];
    s8 unk18875;
    u8 pad18876[0x18B4A - 0x18876];
    u8 unk18B4A;
} Play;

s32 Player_InBlockingCsMode(Play *play, Player *player) {
    return (player->stateFlags1 & 0x20000280) || player->unk394 != 0 || play->unk18875 == 0x14 ||
           play->unk18B4A != 0 || (player->stateFlags1 & 1) || (player->stateFlags3 & 0x80) ||
           play->unk1F08 != 0;
}
