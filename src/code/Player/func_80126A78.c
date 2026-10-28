#include "types.h"

typedef struct { u8 pad0[0x144]; s8 unk144; u8 pad145[0x533]; u8 unk678; u8 pad679[0x3F3]; u32 unkA6C; } Player;
void Matrix_MultVec3f(void *a, void *b);
void func_800E7C1C(s32 a, void *b, void *c, void *d, void *e);
void CollisionCheck_SetAC(s32 a, s32 b, s32 c);
void CollisionCheck_SetAT(s32 a, s32 b, s32 c);
extern u8 D_801C162C[];

void Player_UpdateShieldCollider(s32 play, Player *player, s32 col, u8 *pos) {
    u8 sp4C[12];
    u8 sp40[12];
    u8 sp34[12];
    u8 sp28[12];


    if (player->unkA6C & 0x400000) {
        player->unk678 = D_801C162C[player->unk144];
        Matrix_MultVec3f(pos, sp28);
        Matrix_MultVec3f(pos + 0xC, sp34);
        Matrix_MultVec3f(pos + 0x18, sp40);
        Matrix_MultVec3f(pos + 0x24, sp4C);
        func_800E7C1C(col, sp28, sp34, sp40, sp4C);
         col = col;
        CollisionCheck_SetAC(play, (play + 0x18884), col);
        CollisionCheck_SetAT(play, (play + 0x18884), col);
    }
}
