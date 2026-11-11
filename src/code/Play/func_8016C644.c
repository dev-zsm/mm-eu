// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play_hireso.h"

void BombersNotebook_DrawEntries(Gfx** gfxP, s32 row, u32 rectTop) {
    Gfx* gfx = *gfxP;
    s32 entryRectLeft;
    u32 eventIcon;
    u32 unfinishedEvent = false;
    u16 startTime;
    u16 endTime;
    s32 j = 0;
    u32 iconRectLeft;
    s32 entryRectRight;
    u32 yOffset;
    s32 entryWidth;

    while (true) {
        if (sBombersNotebookEntries[row][j] == BOMBERS_NOTEBOOK_ENTRY_END) {
            if (!unfinishedEvent) {
                gDPPipeSync(gfx++);
                gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                                  PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
                gDPSetEnvColor(gfx++, 0, 0, 0, 255);
                gDPLoadTextureBlock(gfx++, gBombersNotebookStampTex, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 48, 0,
                                    G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                BombersNotebook_DrawScisTexRect(&gfx, 567 * 4, (rectTop + 1) * 4, 599 * 4, (rectTop + 49) * 4, 0, 0, 0,
                                                1 << 10, 1 << 10);
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gDPSetEnvColor(gfx++, 255, 0, 0, 255);
                BombersNotebook_DrawScisTexRect(&gfx, 565 * 4, (rectTop + -1) * 4, 597 * 4, (rectTop + 47) * 4, 0, 0, 0,
                                                1 << 10, 1 << 10);
                gDPPipeSync(gfx++);
                gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                gDPSetEnvColor(gfx++, 0, 0, 0, 255);
            }
            break;
        }

        if (sBombersNotebookEntries[row][j] & BOMBERS_NOTEBOOK_ENTRY_POS_ABOVE) {
            yOffset = 8;
        } else if (sBombersNotebookEntries[row][j] & BOMBERS_NOTEBOOK_ENTRY_POS_BELOW) {
            yOffset = 24;
        } else { 
            yOffset = 16;
        }

        startTime = BOMBERS_NOTEBOOK_ENTRY_GET_START_TIME(row, j) - CLOCK_TIME(6, 0);
        endTime = BOMBERS_NOTEBOOK_ENTRY_GET_END_TIME(row, j) - CLOCK_TIME(6, 0);
        entryRectLeft =
            sBombersNotebookDayRectRectLeft[BOMBERS_NOTEBOOK_ENTRY_GET_DAY(row, j)] + (startTime / CLOCK_TIME(0, 10));
        entryRectRight =
            sBombersNotebookDayRectRectLeft[BOMBERS_NOTEBOOK_ENTRY_GET_DAY(row, j)] + (endTime / CLOCK_TIME(0, 10));
        entryWidth = entryRectRight - entryRectLeft - 8;
        if ((entryRectRight - entryRectLeft) < 8) {
            entryRectLeft = ((entryRectLeft + entryRectRight) - entryRectLeft) - 8;
            entryRectRight = entryRectLeft + 8;
        }

        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gDPLoadTextureBlock(gfx++, gBombersNotebookEntryBoxEndTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 16, 0,
                            G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 2, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        BombersNotebook_DrawScisTexRect(&gfx, (entryRectLeft + 2) * 4, (rectTop + yOffset + 2) * 4,
                                        (entryRectLeft + 6) * 4, (rectTop + yOffset + 18) * 4, 0, 0, 0, 1 << 10,
                                        1 << 10);
        BombersNotebook_DrawScisTexRect(&gfx, (entryRectRight + -2) * 4, (rectTop + yOffset + 2) * 4,
                                        (entryRectRight + 2) * 4, (rectTop + yOffset + 18) * 4, 0, 0x80, 0, 1 << 10,
                                        1 << 10);
        if (entryWidth > 0) {
            gDPLoadTextureBlock(gfx++, gBombersNotebookEntryBoxMiddleTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 16, 0,
                                G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 2, G_TX_NOMASK, G_TX_NOLOD,
                                G_TX_NOLOD);
            BombersNotebook_DrawScisTexRect(&gfx, (entryRectLeft + 6) * 4, (rectTop + yOffset + 2) * 4,
                                            (entryRectLeft + 6 + entryWidth) * 4, (rectTop + yOffset + 18) * 4, 0, 0, 0,
                                            1 << 10, 1 << 10);
        }

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        gDPLoadTextureBlock(gfx++, gBombersNotebookEntryBoxEndTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 16, 0,
                            G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 2, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        
        BombersNotebook_DrawScisTexRect(&gfx, (entryRectLeft * 4) ^ 0, (rectTop + yOffset) * 4, (entryRectLeft + 4) * 4,
                                        (rectTop + yOffset + 16) * 4, 0, 0, 0, 1 << 10, 1 << 10);
        
        BombersNotebook_DrawScisTexRect(&gfx, (entryRectRight + -4) * 4, (rectTop + yOffset) * 4,
                                        (entryRectRight * 4) ^ 0, (rectTop + yOffset + 16) * 4, 0, 0x80, 0, 1 << 10,
                                        1 << 10);
        if (entryWidth > 0) {
            gDPLoadTextureBlock(gfx++, gBombersNotebookEntryBoxMiddleTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 16, 0,
                                G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 2, G_TX_NOMASK, G_TX_NOLOD,
                                G_TX_NOLOD);
            BombersNotebook_DrawScisTexRect(&gfx, (entryRectLeft + 4) * 4, (rectTop + yOffset) * 4,
                                            (entryRectLeft + 4 + entryWidth) * 4, (rectTop + yOffset + 16) * 4, 0, 0, 0,
                                            1 << 10, 1 << 10);
        }

        if (CHECK_WEEKEVENTREG(gBombersNotebookWeekEventFlags[BOMBERS_NOTEBOOK_ENTRY_GET_EVENT(row, j)])) {
            eventIcon =
                sBombersNotebookEventIcons[BOMBERS_NOTEBOOK_ENTRY_GET_EVENT(row, j) - BOMBERS_NOTEBOOK_PERSON_MAX];
            if ((entryRectRight - entryRectLeft) < sBombersNotebookEventIconWidths[eventIcon]) {
                iconRectLeft =
                    (((entryRectLeft - sBombersNotebookEventIconWidths[eventIcon]) + entryRectRight) - entryRectLeft) +
                    3;
            } else {
                iconRectLeft = (((entryRectRight - entryRectLeft) - sBombersNotebookEventIconWidths[eventIcon]) / 2) +
                               entryRectLeft;
            }

            if ((eventIcon == BOMBERS_NOTEBOOK_EVENT_ICON_MASK) || (eventIcon == BOMBERS_NOTEBOOK_EVENT_ICON_RIBBON)) {
                if (sBombersNotebookEntries[row][j] & BOMBERS_NOTEBOOK_ENTRY_POS_ABOVE) {
                    yOffset -= 12;
                } else if (!(sBombersNotebookEntries[row][j] & BOMBERS_NOTEBOOK_ENTRY_POS_BELOW)) {
                    
                    yOffset -= 6;
                }
            }
            gDPLoadTextureBlock(gfx++, sBombersNotebookEventIconTextures[eventIcon], G_IM_FMT_IA, G_IM_SIZ_8b,
                                sBombersNotebookEventIconWidths[eventIcon], sBombersNotebookEventIconHeights[eventIcon],
                                0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

            BombersNotebook_DrawScisTexRect(&gfx, (iconRectLeft + 2) * 4, (rectTop + yOffset + 2) * 4,
                                            (iconRectLeft + 2 + sBombersNotebookEventIconWidths[eventIcon]) * 4,
                                            (rectTop + yOffset + 2 + sBombersNotebookEventIconHeights[eventIcon]) * 4,
                                            0, 0, 0, 1 << 10, 1 << 10);
            if (sBombersNotebookEventColorWeekEventFlags[BOMBERS_NOTEBOOK_ENTRY_GET_EVENT(row, j) -
                                                         BOMBERS_NOTEBOOK_PERSON_MAX] ==
                BOMBERS_NOTEBOOK_EVENT_COLOR_WEEKEVENTREG_NONE) {
                gDPSetPrimColor(gfx++, 0, 0, sBombersNotebookEntryIconColors[eventIcon][0],
                                sBombersNotebookEntryIconColors[eventIcon][1],
                                sBombersNotebookEntryIconColors[eventIcon][2], 255);
            } else if (sBombersNotebookEventColorWeekEventFlags[BOMBERS_NOTEBOOK_ENTRY_GET_EVENT(row, j) -
                                                                BOMBERS_NOTEBOOK_PERSON_MAX] ==
                       BOMBERS_NOTEBOOK_EVENT_COLOR_WEEKEVENTREG_DEPOSITED_LETTER_TO_KAFEI) {
                if (CHECK_WEEKEVENTREG(WEEKEVENTREG_DEPOSITED_LETTER_TO_KAFEI_SOUTH_UPPER_CLOCKTOWN) ||
                    CHECK_WEEKEVENTREG(WEEKEVENTREG_DEPOSITED_LETTER_TO_KAFEI_NORTH_CLOCKTOWN) ||
                    CHECK_WEEKEVENTREG(WEEKEVENTREG_DEPOSITED_LETTER_TO_KAFEI_EAST_UPPER_CLOCKTOWN) ||
                    CHECK_WEEKEVENTREG(WEEKEVENTREG_DEPOSITED_LETTER_TO_KAFEI_EAST_LOWER_CLOCKTOWN) ||
                    CHECK_WEEKEVENTREG(WEEKEVENTREG_DEPOSITED_LETTER_TO_KAFEI_SOUTH_LOWER_CLOCKTOWN)) {
                    gDPSetPrimColor(gfx++, 0, 0, sBombersNotebookEntryIconColors[eventIcon][0],
                                    sBombersNotebookEntryIconColors[eventIcon][1],
                                    sBombersNotebookEntryIconColors[eventIcon][2], 255);
                } else {
                    gDPSetPrimColor(gfx++, 0, 0, 155, 155, 155, 255);
                }
            } else {
                if (CHECK_WEEKEVENTREG(
                        sBombersNotebookEventColorWeekEventFlags[BOMBERS_NOTEBOOK_ENTRY_GET_EVENT(row, j) -
                                                                 BOMBERS_NOTEBOOK_PERSON_MAX])) {
                    gDPSetPrimColor(gfx++, 0, 0, sBombersNotebookEntryIconColors[eventIcon][0],
                                    sBombersNotebookEntryIconColors[eventIcon][1],
                                    sBombersNotebookEntryIconColors[eventIcon][2], 255);
                } else {
                    gDPSetPrimColor(gfx++, 0, 0, 155, 155, 155, 255);
                }
            }
            BombersNotebook_DrawScisTexRect(&gfx, iconRectLeft * 4, (rectTop + yOffset) * 4,
                                            (iconRectLeft + sBombersNotebookEventIconWidths[eventIcon]) * 4,
                                            (rectTop + yOffset + sBombersNotebookEventIconHeights[eventIcon]) * 4, 0, 0,
                                            0, 1 << 10, 1 << 10);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            unfinishedEvent = true;
        }
        j += BOMBERS_NOTEBOOK_ENTRY_SIZE;
    }

    *gfxP = gfx;
}
