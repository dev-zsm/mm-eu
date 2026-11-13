// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_scope_NES.h"

void func_8000C060(PlayState* play) {
    PauseContext* pauseCtx = &play->pauseCtx;
    u16 namedItem;

    if ((pauseCtx->namedItem != pauseCtx->cursorItem[pauseCtx->pageIndex]) ||
    ((pauseCtx->pageIndex == PAUSE_MAP) && (pauseCtx->cursorSpecialPos != 0))) {

        pauseCtx->namedItem = pauseCtx->cursorItem[pauseCtx->pageIndex];
        namedItem = pauseCtx->namedItem;

        osCreateMesgQueue(&pauseCtx->loadQueue, &pauseCtx->loadMsg, 1);

        if (pauseCtx->namedItem != PAUSE_ITEM_NONE) {
            if ((pauseCtx->pageIndex == PAUSE_MAP) && !sInDungeonScene) {
                Kaleido_LoadMapNameStatic(pauseCtx->nameSegment, namedItem);
            } else {
                Kaleido_LoadItemNameStatic(pauseCtx->nameSegment, namedItem);
            }
            pauseCtx->nameDisplayTimer = 0;
        }
    } else if (pauseCtx->nameColorSet == PAUSE_NAME_COLOR_SET_WHITE) {
        if (((pauseCtx->pageIndex == PAUSE_QUEST) && (pauseCtx->cursorSlot[PAUSE_QUEST] >= QUEST_SONG_SONATA) &&
        (pauseCtx->cursorSlot[PAUSE_QUEST] <= QUEST_SONG_SUN) &&
        (pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE_CURSOR_ON_SONG)) ||
        ((pauseCtx->pageIndex == PAUSE_QUEST) && (pauseCtx->cursorSlot[PAUSE_QUEST] == QUEST_BOMBERS_NOTEBOOK)) ||
        (pauseCtx->pageIndex == PAUSE_ITEM) || (pauseCtx->pageIndex == PAUSE_MASK)) {

            pauseCtx->nameDisplayTimer++;
            if (pauseCtx->nameDisplayTimer > 70) {
                pauseCtx->nameDisplayTimer = 0;
            }
        } else {
            pauseCtx->nameDisplayTimer = 0;
        }
    } else {
        pauseCtx->nameDisplayTimer = 0;
    }
}
