// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_select.h"

void MapSelect_PrintCutsceneSetting(MapSelectState* this, GfxPrint* printer, u16 csIndex) {
    const char* stage;
    const char* day;

    GfxPrint_SetPos(printer, 4, 25);
    GfxPrint_SetColor(printer, 255, 255, 55, 255);

    
    switch (csIndex) {
        case 0:
            
            
            gSaveContext.save.time = CLOCK_TIME(12, 0); stage = GFXP_HIRAGANA "ｵﾋﾙ" GFXP_KATAKANA "ｼﾞｬﾗ";
            
            break;

        case 0x8000:
            
            
            gSaveContext.save.time = CLOCK_TIME(6, 0) + 1; stage = GFXP_HIRAGANA "ｱｻ " GFXP_KATAKANA "ｼﾞｬﾗ";
            
            break;

        case 0x8800:
            gSaveContext.save.time = CLOCK_TIME(18, 1);
            
            stage = GFXP_HIRAGANA "ﾖﾙ " GFXP_KATAKANA "ｼﾞｬﾗ";
            break;

        case 0xFFF0:
            
            
            gSaveContext.save.time = CLOCK_TIME(12, 0); stage = "ﾃﾞﾓ00";
            
            break;

        case 0xFFF1:
            
            stage = "ﾃﾞﾓ01";
            break;

        case 0xFFF2:
            
            stage = "ﾃﾞﾓ02";
            break;

        case 0xFFF3:
            
            stage = "ﾃﾞﾓ03";
            break;

        case 0xFFF4:
            
            stage = "ﾃﾞﾓ04";
            break;

        case 0xFFF5:
            
            stage = "ﾃﾞﾓ05";
            break;

        case 0xFFF6:
            
            stage = "ﾃﾞﾓ06";
            break;

        case 0xFFF7:
            
            stage = "ﾃﾞﾓ07";
            break;

        case 0xFFF8:
            
            stage = "ﾃﾞﾓ08";
            break;

        case 0xFFF9:
            
            stage = "ﾃﾞﾓ09";
            break;

        case 0xFFFA:
            
            stage = "ﾃﾞﾓ0A";
            break;

        default:
            stage = "???";
            break;
    }
    gSaveContext.skyboxTime = CURRENT_TIME;
    GfxPrint_Printf(printer, "Stage:" GFXP_KATAKANA "%s", stage);

    GfxPrint_SetPos(printer, 23, 25);
    GfxPrint_SetColor(printer, 255, 255, 55, 255);

    switch (gSaveContext.save.day) {
        case 1:
            
            day = GFXP_HIRAGANA "ｻｲｼｮﾉﾋ";
            break;

        case 2:
            
            day = GFXP_HIRAGANA "ﾂｷﾞﾉﾋ";
            break;

        case 3:
            
            day = GFXP_HIRAGANA "ｻｲｺﾞﾉﾋ";
            break;

        case 4:
            
            day = GFXP_HIRAGANA "ｸﾘｱｰﾉﾋ";
            break;

        default:
            gSaveContext.save.day = 1;
            
            day = GFXP_HIRAGANA "ｻｲｼｮﾉﾋ";
            break;
    }

    GfxPrint_Printf(printer, "Day:" GFXP_HIRAGANA "%s", day);
}
