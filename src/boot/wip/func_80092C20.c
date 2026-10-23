// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u16 imageW;
    /* 0x02 */ u16 imageH2;
    /* 0x04 */ u16 pad4;
    /* 0x06 */ u16 imageH;
    /* 0x08 */ u8 pad8[0xC];
    /* 0x14 */ u16 imageFmt;
    /* 0x16 */ u8 imageSiz;
    /* 0x17 */ u8 imageLoad;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ s16 tmemW;
    /* 0x1E */ s16 tmemH;
    /* 0x20 */ s16 tmemLoadSH;
    /* 0x22 */ s16 tmemLoadTH;
    /* 0x24 */ u16 tmemSizeW;
    /* 0x26 */ u16 tmemSize;
} uObjBg;

void guS2DInitBg(uObjBg *bg) {
    s32 tmem;
    u16 shift;
    u16 w;
    s32 t;
    u16 h;
    u16 sz;
    u16 prod;
    u32 prod2;

    tmem = (bg->imageSiz == 2) ? 0x100 : 0x200;
    shift = 6 - bg->imageLoad;
    if (bg->imageFmt == 0x33) {
        t = bg->imageH2 >> shift;
        w = t;
        h = (tmem / w) * 4;
        sz = w * 2;
        prod = h * sz;
        bg->tmemW = t;
        bg->tmemH = h;
        bg->tmemSizeW = sz;
        bg->tmemSize = prod;
        bg->tmemLoadSH = (prod >> 1) - 1;
        bg->tmemLoadTH = 0x7FF / w + 1;
    } else {
        bg->tmemW = (bg->imageH >> shift) + 3;
        h = (tmem / (u16)((bg->imageH >> shift) + 3)) * 4;
        bg->tmemH = h;
        bg->tmemSizeW = (bg->imageH2 >> shift) * 2;
        prod2 = h * (u16)bg->tmemSizeW;
        bg->tmemSize = prod2 >> 16;
        bg->tmemLoadSH = prod2;
        bg->tmemLoadTH = h - 1;
    }
}
