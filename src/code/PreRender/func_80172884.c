// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/PreRender.h"

u32 PreRender_Get5bMedian9(u8* px1, u8* px2, u8* px3) {
    u8 pxValCount[32]; 
    u32 pxCount;       
    s32 pxMed;         

    
    *(s32*)(&pxValCount[0]) = 0;
    *(s32*)(&pxValCount[4]) = 0;
    *(s32*)(&pxValCount[8]) = 0;
    *(s32*)(&pxValCount[12]) = 0;
    *(s32*)(&pxValCount[16]) = 0;
    *(s32*)(&pxValCount[20]) = 0;
    *(s32*)(&pxValCount[24]) = 0;
    *(s32*)(&pxValCount[28]) = 0;

    
    pxValCount[px1[0]]++;
    pxValCount[px1[1]]++;
    pxValCount[px1[2]]++;

    pxValCount[px2[0]]++;
    pxValCount[px2[1]]++;
    pxValCount[px2[2]]++;

    pxValCount[px3[0]]++;
    pxValCount[px3[1]]++;
    pxValCount[px3[2]]++;

    
    
    pxCount = 0;
    pxMed = 0;
    while (true) {
        pxCount += pxValCount[pxMed];
        if (pxCount >= 5) {
            
            break;
        }
        pxMed++;
    }

    return pxMed;
}
