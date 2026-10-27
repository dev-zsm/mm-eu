#include "types.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ s32 unk24;
} BgInfo;

extern void Prerender_DrawBackground2DImpl(BgInfo *, s32);

void Prerender_DrawBackground2D(s32 a0, s32 a1, s32 a2, u16 a3, u16 a4, u8 a5, u8 a6, u16 a7, u16 a8, f32 a9, f32 a10, f32 a11, f32 a12, s32 a13) {
    BgInfo info;
    s32 pad[2];

    info.unk0 = a1;
    info.unk4 = a2;
    info.unk8 = a3;
    info.unkA = a4;
    info.unkC = a5;
    info.unkD = a6;
    info.unkE = a7;
    info.unk10 = a8;
    info.unk14 = a9;
    info.unk18 = a10;
    info.unk1C = a11;
    info.unk20 = a12;
    info.unk24 = a13;
    Prerender_DrawBackground2DImpl(&info, a0);
}
