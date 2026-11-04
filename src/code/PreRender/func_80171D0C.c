// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/PreRender.h"

void PreRender_AntiAliasFilterPixel(PreRender* this, s32 x, s32 y) {
    s32 i;
    s32 j;
    s32 buffCvg[3 * 5];
    s32 buffR[3 * 5];
    s32 buffG[3 * 5];
    s32 buffB[3 * 5];
    s32 xi;
    s32 yi;
    s32 invCvg;
    s32 pmaxR;
    s32 pmaxG;
    s32 pmaxB;
    s32 pminR;
    s32 pminG;
    s32 pminB;
    Color_RGBA16 pxIn;
    Color_RGBA16 pxOut;
    u32 outR;
    u32 outG;
    u32 outB;

    
    for (i = 0; i < 5 * 3; i++) {
        xi = x + (i % 5) - 2;
        yi = y + (i / 5) - 1;

        
        if (xi < 0) {
            xi = 0;
        } else if (xi > (this->width - 1)) {
            xi = this->width - 1;
        }
        if (yi < 0) {
            yi = 0;
        } else if (yi > (this->height - 1)) {
            yi = this->height - 1;
        }

        
        pxIn.rgba = this->fbufSave[xi + yi * this->width];
        buffR[i] = (pxIn.r << 3) | (pxIn.r >> 2);
        buffG[i] = (pxIn.g << 3) | (pxIn.g >> 2);
        buffB[i] = (pxIn.b << 3) | (pxIn.b >> 2);
        buffCvg[i] = this->cvgSave[xi + yi * this->width] >> 5;
    }

    pmaxR = pminR = buffR[7];
    pmaxG = pminG = buffG[7];
    pmaxB = pminB = buffB[7];

    
    for (i = 1; i < 5 * 3; i += 2) {
        
        if (buffCvg[i] != 7) {
            continue;
        }
        

        
        if (pmaxR < buffR[i]) {
            
            for (j = 1; j < 5 * 3; j += 2) {
                
                
                if ((i != j) && (buffR[j] >= buffR[i]) && (buffCvg[j] == 7)) {
                    pmaxR = buffR[i];
                }
            }
        }
        if (pmaxG < buffG[i]) {
            for (j = 1; j < 5 * 3; j += 2) {
                if ((i != j) && (buffG[j] >= buffG[i]) && (buffCvg[j] == 7)) {
                    pmaxG = buffG[i];
                }
            }
        }
        if (pmaxB < buffB[i]) {
            for (j = 1; j < 5 * 3; j += 2) {
                if ((i != j) && (buffB[j] >= buffB[i]) && (buffCvg[j] == 7)) {
                    pmaxB = buffB[i];
                }
            }
        }

        

        
        if (pminR > buffR[i]) {
            for (j = 1; j < 5 * 3; j += 2) {
                if ((i != j) && (buffR[j] <= buffR[i]) && (buffCvg[j] == 7)) {
                    pminR = buffR[i];
                }
            }
        }
        if (pminG > buffG[i]) {
            for (j = 1; j < 5 * 3; j += 2) {
                if ((i != j) && (buffG[j] <= buffG[i]) && (buffCvg[j] == 7)) {
                    pminG = buffG[i];
                }
            }
        }
        if (pminB > buffB[i]) {
            for (j = 1; j < 5 * 3; j += 2) {
                if ((i != j) && (buffB[j] <= buffB[i]) && (buffCvg[j] == 7)) {
                    pminB = buffB[i];
                }
            }
        }
    }

    
    
    

    
    invCvg = 7 - buffCvg[7];
    outR = buffR[7] + ((s32)(invCvg * (pmaxR + pminR - (buffR[7] * 2)) + 4) >> 3);
    outG = buffG[7] + ((s32)(invCvg * (pmaxG + pminG - (buffG[7] * 2)) + 4) >> 3);
    outB = buffB[7] + ((s32)(invCvg * (pmaxB + pminB - (buffB[7] * 2)) + 4) >> 3);

    pxOut.r = outR >> 3;
    pxOut.g = outG >> 3;
    pxOut.b = outB >> 3;
    pxOut.a = 1;
    this->fbufSave[x + y * this->width] = pxOut.rgba;
}
