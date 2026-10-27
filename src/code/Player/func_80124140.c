#include "types.h"
typedef struct {
    u8 pad0[0x144];
    u8 unk144;
    s8 unk145;
    u8 pad146;
    s8 unk147;
    u8 pad148[3];
    u8 unk14B;
    u8 pad14C[0x394 - 0x14C];
    u8 unk394;
    u8 pad395[0xB62 - 0x395];
    s16 unkB62;
} Player;
extern u16 D_801E6F5C;
extern u16 D_801C2A72;
extern u8 D_801C2AC1;
extern u8 D_801C0C50[];
extern s32 Player_ActionToModelGroup(Player *, s32);
extern void Player_SetModelGroup(Player *, s32);
extern void func_801235F0(void *, Player *);

void Player_SetEquipmentData(void *play, Player *player) {
    u16 a; // temp exists only to match register allocation
    if (player->unk394 != 0x86) {
        a = D_801E6F5C;
        player->unk144 = (a & D_801C2A72) >> D_801C2AC1;
        if (player->unk14B != 2 || (player->unk145 != 4 && player->unk145 != 5)) {
            player->unk145 = D_801C0C50[player->unk14B];
        }
        Player_SetModelGroup(player, Player_ActionToModelGroup(player, player->unk147));
        func_801235F0(play, player);
        if (player->unkB62 != 0) {
            player->unkB62 = 1;
        }
    }
}
