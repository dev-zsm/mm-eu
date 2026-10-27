// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    u8 pad0[0x70];
    f32 unk70;
    u8 pad74[0x1C];
    u16 unk90;
    u8 pad92[0x145 - 0x92];
    s8 unk145;
    u8 pad146[5];
    u8 unk14B;
    u8 pad14C[0xA6C - 0x14C];
    u32 unkA6C;
    u32 unkA70;
} Player;
typedef struct {
    u8 pad[0x1CCC];
    Player *player;
} Play;
s32 func_80123984(Play *play) {
    Player *p = play->player;
    return ((p->unkA70 & 8) != 0) || (p->unk70 != 0.0f) ||
           ((p->unk14B != 2) && ((p->unkA6C & 0x08000000) != 0)) ||
           ((p->unk14B == 2) && ((p->unkA6C & 0x08000000) != 0) && (((p->unk90 & 1) == 0) || (p->unk145 < 5)));
}
