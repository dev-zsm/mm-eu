#include "types.h"

typedef struct {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 unk9;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
} TitleCardBossName;

void TitleCard_InitBossName(void *arg0, TitleCardBossName *name, s32 arg2, s16 arg3, s16 arg4, u8 arg5, u8 arg6) {
    name->unk0 = arg2;
    name->unk4 = arg3;
    name->unk6 = arg4;
    name->unk8 = arg5;
    name->unk9 = arg6;
    name->unkA = 0x50;
    name->unkB = 0;
}
