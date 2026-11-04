// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/PreRender.h"

void PreRender_DivotFilter(PreRender* this) {
    u32 width = this->width;
    u32 height = this->height;
    u8* buffer = alloca(width * 10);
    u8* redRow[3];
    u8* greenRow[3];
    u8* blueRow[3];
    u8* cvgFull;
    Color_RGBA16 inPx;
    Color_RGBA16 outPx;
    u32 x;
    u32 y;
    s32 pad;

    redRow[0] = &buffer[width * 0];
    redRow[1] = &buffer[width * 1];
    redRow[2] = &buffer[width * 2];

    greenRow[0] = &buffer[width * 3];
    greenRow[1] = &buffer[width * 4];
    greenRow[2] = &buffer[width * 5];

    blueRow[0] = &buffer[width * 6];
    blueRow[1] = &buffer[width * 7];
    blueRow[2] = &buffer[width * 8];

    cvgFull = &buffer[width * 9];

    
    for (y = 0; y < 2; y++) {
        for (x = 0; x < width; x++) {
            inPx.rgba = this->fbufSave[x + y * this->width];

            redRow[y][x] = inPx.r;
            greenRow[y][x] = inPx.g;
            blueRow[y][x] = inPx.b;
        }
    }

    
    for (y = 1; y < height - 1; y++) {
        
        
        u8* redRow2 = redRow[2];
        u8* greenRow2 = greenRow[2];
        u8* blueRow2 = blueRow[2];
        u8* lineCvg = &this->cvgSave[width * y];
        u16* linePx = &this->fbufSave[width * y];

        
        
        for (x = 0; x < width; x++) {
            inPx.rgba = linePx[x];

            redRow2[x] = inPx.r;
            greenRow2[x] = inPx.g;
            blueRow2[x] = inPx.b;

            
            cvgFull[x] = (lineCvg[x] >> 5) == 7;
        }

        for (x = 1; x < width - 1; x++) {
            
            if (cvgFull[x - 1] && cvgFull[x] && cvgFull[x + 1]) {
                continue;
            }

            
            
            
            
            outPx.r = PreRender_Get5bMedian9(&redRow[0][x - 1], &redRow[1][x - 1], &redRow[2][x - 1]);
            outPx.g = PreRender_Get5bMedian9(&greenRow[0][x - 1], &greenRow[1][x - 1], &greenRow[2][x - 1]);
            outPx.b = PreRender_Get5bMedian9(&blueRow[0][x - 1], &blueRow[1][x - 1], &blueRow[2][x - 1]);
            outPx.a = 1;

            this->fbufSave[x + y * this->width] = outPx.rgba;
        }

        
        redRow[0] = redRow[1];
        greenRow[0] = greenRow[1];
        blueRow[0] = blueRow[1];
        
        redRow[1] = redRow[2];
        greenRow[1] = greenRow[2];
        blueRow[1] = blueRow[2];
    }
}
