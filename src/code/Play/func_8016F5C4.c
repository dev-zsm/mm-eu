// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play_hireso.h"

void BombersNotebook_DrawCursor(BombersNotebook* this, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    s32 cursorRow;
    s32 cursorEntry;
    s32 entryRectRight;
    s32 entryRectLeft;
    s32 entryIcon;
    u32 cursorRectLeft;
    u32 cursorRectTop;
    u32 yOffset;
    u16 startTime;
    u16 endTime;

    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE,
                      ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 205, 55, 255);
    gDPSetEnvColor(gfx++, 0, 0, 0, 255);
    gDPLoadTextureBlock_4b(gfx++, gBombersNotebookCursorTex, G_IM_FMT_IA, 16, 16, 0, G_TX_MIRROR | G_TX_WRAP,
                           G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    if (this->cursorEntry == 0) {
        BombersNotebook_DrawScisTexRect(&gfx, 47 * 4, (this->cursorPageRow * 52 + 97) * 4, 63 * 4,
                                        (this->cursorPageRow * 52 + 113) * 4, 0, 0, 0, 1 << 10, 1 << 10);
        BombersNotebook_DrawScisTexRect(&gfx, 98 * 4, (this->cursorPageRow * 52 + 97) * 4, 114 * 4,
                                        (this->cursorPageRow * 52 + 113) * 4, 0, 0x200, 0, 1 << 10, 1 << 10);
        BombersNotebook_DrawScisTexRect(&gfx, 47 * 4, (this->cursorPageRow * 52 + 147) * 4, 63 * 4,
                                        (this->cursorPageRow * 52 + 163) * 4, 0, 0, 0x200, 1 << 10, 1 << 10);
        BombersNotebook_DrawScisTexRect(&gfx, 98 * 4, (this->cursorPageRow * 52 + 147) * 4, 114 * 4,
                                        (this->cursorPageRow * 52 + 163) * 4, 0, 0x200, 0x200, 1 << 10, 1 << 10);
    } else {
        cursorRow = this->cursorPageRow + this->cursorPage;
        cursorRectTop = (this->cursorPageRow * 52) + 107;
        cursorEntry = this->cursorEntry - BOMBERS_NOTEBOOK_ENTRY_SIZE; 
        if (sBombersNotebookEntries[cursorRow][cursorEntry] & BOMBERS_NOTEBOOK_ENTRY_POS_ABOVE) {
            yOffset = 8;
        } else if (sBombersNotebookEntries[cursorRow][cursorEntry] & BOMBERS_NOTEBOOK_ENTRY_POS_BELOW) {
            yOffset = 24;
        } else { 
            yOffset = 16;
        }

        startTime = BOMBERS_NOTEBOOK_ENTRY_GET_START_TIME(cursorRow, cursorEntry) - CLOCK_TIME(6, 0);
        endTime = BOMBERS_NOTEBOOK_ENTRY_GET_END_TIME(cursorRow, cursorEntry) - CLOCK_TIME(6, 0);
        entryRectLeft = sBombersNotebookDayRectRectLeft[BOMBERS_NOTEBOOK_ENTRY_GET_DAY(cursorRow, cursorEntry)] +
                        (startTime / CLOCK_TIME(0, 10));
        entryRectRight = sBombersNotebookDayRectRectLeft[BOMBERS_NOTEBOOK_ENTRY_GET_DAY(cursorRow, cursorEntry)] +
                         (endTime / CLOCK_TIME(0, 10));
        if ((entryRectRight - entryRectLeft) < 8) {
            entryRectLeft = ((entryRectLeft + entryRectRight) - entryRectLeft) - 8;
            entryRectRight = entryRectLeft + 8;
        }
        entryIcon = sBombersNotebookEventIcons[BOMBERS_NOTEBOOK_ENTRY_GET_EVENT(cursorRow, cursorEntry) -
                                               BOMBERS_NOTEBOOK_PERSON_MAX];
        if ((entryRectRight - entryRectLeft) < sBombersNotebookEventIconWidths[entryIcon]) {
            cursorRectLeft =
                (((entryRectLeft - sBombersNotebookEventIconWidths[entryIcon]) + entryRectRight) - entryRectLeft) + 3;
        } else {
            cursorRectLeft =
                (((entryRectRight - entryRectLeft) - sBombersNotebookEventIconWidths[entryIcon]) / 2) + entryRectLeft;
        }
        if (entryIcon == BOMBERS_NOTEBOOK_EVENT_ICON_EXCLAMATION_POINT) {
            cursorRectLeft -= 8;
            cursorRectTop -= 8;
        } else {
            cursorRectLeft -= 9;
            cursorRectTop -= 8;
        }
        if ((entryIcon == BOMBERS_NOTEBOOK_EVENT_ICON_MASK) || (entryIcon == BOMBERS_NOTEBOOK_EVENT_ICON_RIBBON)) {
            if (sBombersNotebookEntries[cursorRow][cursorEntry] & BOMBERS_NOTEBOOK_ENTRY_POS_ABOVE) {
                yOffset -= 12;
            } else if (!(sBombersNotebookEntries[cursorRow][cursorEntry] & BOMBERS_NOTEBOOK_ENTRY_POS_BELOW)) {
                
                yOffset -= 6;
            }
        }
        BombersNotebook_DrawScisTexRect(&gfx, cursorRectLeft * 4, (cursorRectTop + yOffset) * 4,
                                        (cursorRectLeft + 16) * 4, (cursorRectTop + yOffset + 16) * 4, 0, 0, 0, 1 << 10,
                                        1 << 10);
        BombersNotebook_DrawScisTexRect(&gfx, (cursorRectLeft + sBombersNotebookEventIconWidths[entryIcon]) * 4,
                                        (cursorRectTop + yOffset) * 4,
                                        (cursorRectLeft + sBombersNotebookEventIconWidths[entryIcon] + 16) * 4,
                                        (cursorRectTop + yOffset + 16) * 4, 0, 0x200, 0, 1 << 10, 1 << 10);
        BombersNotebook_DrawScisTexRect(
            &gfx, cursorRectLeft * 4, (cursorRectTop + yOffset + sBombersNotebookEventIconHeights[entryIcon]) * 4,
            (cursorRectLeft + 16) * 4, (cursorRectTop + yOffset + sBombersNotebookEventIconHeights[entryIcon] + 16) * 4,
            0, 0, 0x200, 1 << 10, 1 << 10);
        BombersNotebook_DrawScisTexRect(&gfx, (cursorRectLeft + sBombersNotebookEventIconWidths[entryIcon]) * 4,
                                        (cursorRectTop + yOffset + sBombersNotebookEventIconHeights[entryIcon]) * 4,
                                        (cursorRectLeft + sBombersNotebookEventIconWidths[entryIcon] + 16) * 4,
                                        (cursorRectTop + yOffset + sBombersNotebookEventIconHeights[entryIcon] + 16) *
                                            4,
                                        0, 0x200, 0x200, 1 << 10, 1 << 10);
    }

    gDPPipeSync(gfx++);
    *gfxP = gfx;
}
