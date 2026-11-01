// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xA74];
    u32 unkA74;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player *unk1CCC;
} Play;

typedef struct {
    u8 pad0[0x8C];
    Play *unk8C;
    Player *unk90;
} Thing;

s32 func_800CB6D4(Thing *t) {
    if (t->unk90 != t->unk8C->unk1CCC) {
        return 0;
    }
    return t->unk90->unkA74 & 0x1000;
}
