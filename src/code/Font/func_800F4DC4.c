// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kanfont.h"

void Font_LoadOrderedFont(Font* font) {
    u32 loadOffset;
    s32 codePointIndex = 0;
    u8* writeLocation;

    while (1) {
        writeLocation = &font->fontBuf[codePointIndex * FONT_CHAR_TEX_SIZE];
        loadOffset = sFontOrdering[codePointIndex] * FONT_CHAR_TEX_SIZE;
        if (sFontOrdering[codePointIndex] == 0) {
            loadOffset = 0;
        }

        DmaMgr_RequestSync(writeLocation, SEGMENT_ROM_START(nes_font_static) + loadOffset, FONT_CHAR_TEX_SIZE);
        if (sFontOrdering[codePointIndex] == 0x8F) {
            break;
        }
        codePointIndex++;
    }
}
