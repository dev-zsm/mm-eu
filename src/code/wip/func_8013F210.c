#include "types.h"

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ s16 unkC;
    /* 0xE */ s16 unkE;
} Vp_8013F210;

typedef struct {
    s32 leftX;
    s32 rightX;
    s32 topY;
    s32 bottomY;
} Viewport_8013F210;

void View_ViewportToVp(Vp_8013F210 *arg0, Viewport_8013F210 *arg1) {
    s32 w = arg1->bottomY - arg1->topY;
    s32 h = arg1->rightX - arg1->leftX;

    arg0->unk0 = w * 2;
    arg0->unk2 = h * 2;
    arg0->unk4 = 0x1FF;
    arg0->unk6 = 0;
    arg0->unk8 = (arg1->topY * 2 + w) * 2;
    arg0->unkC = 0x1FF;
    arg0->unkE = 0;
    arg0->unkA = (arg1->leftX * 2 + h) * 2;
    if (arg1->topY == 0 && arg1->bottomY == 0x240 && arg1->leftX == 0) {
    } else {
    }
}
