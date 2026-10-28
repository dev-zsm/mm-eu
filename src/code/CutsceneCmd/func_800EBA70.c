#include "types.h"

typedef struct {
    u8 pad[0x10];
    u16 unk10;
} A;
typedef struct {
    u16 unk0;
    u16 unk2;
} B;
typedef struct {
    u8 pad[0x24];
    s32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 pad30[0xA80 - 0x30];
    s32 unkA80;
} P;
extern s8 D_801E6F12;
s32 Actor_Spawn(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32);
void CutsceneCmd_GiveTatlToPlayer(u8 *play, A *a, B *cmd) {
    P *player = *((P **) (play + 0x1CCC));
    long long new_var2;
    u8 *new_var;
    if ((a->unk10 == cmd->unk2) && (1 == cmd->unk0)) {
        if (1) {
        }
        D_801E6F12 = (new_var2 = 1);
        if (player->unkA80 == 0) {
            new_var = play + 0x1CA0;
            player->unkA80 = Actor_Spawn(new_var, play, 0x10, player->unk24, player->unk28, player->unk2C, 0, 0, 0, 0);
        }
    }
}
