#include "types.h"

typedef struct {
    u8 pad0[0x16950];
    s16 unk16950;
    u8 pad1[0x170E6 - 0x16952];
    u8 unk170E6;
    u8 pad2[0x186E2 - 0x170E7];
    u8 unk186E2;
    u8 unk186E3;
    u8 pad3;
    u8 unk186E5;
    u8 unk186E6;
} Ctx;
typedef struct {
    u8 pad0[1];
    u8 unk1;
    u8 pad2[2];
    u32 w;
} Cmd;
void Scene_CommandRoomBehavior(Ctx *c, Cmd *cmd) {
    u8 new_var;
    Ctx *new_var2;
    new_var = cmd->unk1;
    new_var2 = c;
    c->unk186E3 = new_var & 0xFF;
    new_var2->unk186E2 = cmd->w & 0xFF;
    new_var2->unk186E5 = (cmd->w >> ((0, 8))) & 1;
    new_var2->unk16950 = (cmd->w >> 10) & 1;
    new_var2->unk186E6 = (cmd->w >> 11) & 1;
    new_var2->unk170E6 = (cmd->w >> 12) & 1;
}
