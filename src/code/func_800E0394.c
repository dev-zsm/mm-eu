// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    u8 pad4[0xC];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
} Collider;

s32 Collider_SetBaseType1(s32 arg0, Collider *c, s32 arg2, u8 *arg3) {
    c->unk0 = arg2;
    c->unk14 = arg3[0];
    c->unk10 = arg3[1];
    c->unk11 = arg3[2];
    c->unk12 = arg3[3];
    c->unk13 = 0x10;
    c->unk15 = arg3[4];
    return 1;
}
