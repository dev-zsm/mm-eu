// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// matching: IDO 5.3, u16 shift local, tmem chosen from imageFmt
#include "gu.h"

void guS2DInitBg(uObjBg *bg) {
    u32 size;
    s32 tmem = (bg->imageFmt == 2) ? 0x100 : 0x200;
    u16 shift = 6 - bg->imageSiz;

    if (bg->imageLoad == 0x33) {
        bg->tmemW = bg->imageW >> shift;
        bg->tmemH = tmem / bg->tmemW * 4;
        bg->tmemSizeW = bg->tmemW * 2;
        bg->tmemSize = bg->tmemH * bg->tmemSizeW;
        bg->tmemLoadSH = (bg->tmemSize >> 1) - 1;
        bg->tmemLoadTH = 0x7FF / bg->tmemW + 1;
    } else {
        bg->tmemW = (bg->frameW >> shift) + 3;
        bg->tmemH = tmem / bg->tmemW * 4;
        bg->tmemSizeW = (bg->imageW >> shift) * 2;
        size = bg->tmemH * bg->tmemSizeW;
        bg->tmemSize = size >> 16;
        bg->tmemLoadSH = size & 0xFFFF;
        bg->tmemLoadTH = bg->tmemH - 1;
    }
}
