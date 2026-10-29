// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// matching: IDO 5.3, u16 shift local, tmem chosen from imageFmt
#include "types.h"

typedef struct {
    /* 0x00 */ u16 imageW;
    /* 0x02 */ u16 imageW2;
    /* 0x04 */ u16 pad4;
    /* 0x06 */ u16 frameW;
    /* 0x08 */ u8 pad8[0xC];
    /* 0x14 */ u16 imageLoad;
    /* 0x16 */ u8 imageFmt;
    /* 0x17 */ u8 imageSiz;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ u16 tmemW;
    /* 0x1E */ u16 tmemH;
    /* 0x20 */ u16 tmemLoadSH;
    /* 0x22 */ u16 tmemLoadTH;
    /* 0x24 */ u16 tmemSizeW;
    /* 0x26 */ u16 tmemSize;
} uObjBg;

void guS2DInitBg(uObjBg *bg) {
    u32 size;
    s32 tmem = (bg->imageFmt == 2) ? 0x100 : 0x200;
    u16 shift = 6 - bg->imageSiz;

    if (bg->imageLoad == 0x33) {
        bg->tmemW = bg->imageW2 >> shift;
        bg->tmemH = tmem / bg->tmemW * 4;
        bg->tmemSizeW = bg->tmemW * 2;
        bg->tmemSize = bg->tmemH * bg->tmemSizeW;
        bg->tmemLoadSH = (bg->tmemSize >> 1) - 1;
        bg->tmemLoadTH = 0x7FF / bg->tmemW + 1;
    } else {
        bg->tmemW = (bg->frameW >> shift) + 3;
        bg->tmemH = tmem / bg->tmemW * 4;
        bg->tmemSizeW = (bg->imageW2 >> shift) * 2;
        size = bg->tmemH * bg->tmemSizeW;
        bg->tmemSize = size >> 16;
        bg->tmemLoadSH = size & 0xFFFF;
        bg->tmemLoadTH = bg->tmemH - 1;
    }
}
