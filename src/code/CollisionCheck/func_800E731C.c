// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    u8 pad4[0xC];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16;
    u8 unk17;
} Info;

typedef struct {
    u8 unk0;
    u8 pad1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8;
} Src;

void CollisionCheck_SetInfo2(Info *info, s32 a1, Src *src) {
    info->unk17 = src->unk0;
    info->unk0 = a1;
    info->unk10 = src->unk2;
    info->unk12 = src->unk4;
    info->unk14 = src->unk6;
    info->unk16 = src->unk8;
}
