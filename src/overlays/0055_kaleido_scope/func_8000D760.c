// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_scope_NES.h"

void func_8000D760(PlayState* play, GraphicsContext* gfxCtx) {
    PauseContext* pauseCtx = &play->pauseCtx;
    s16 i;
    s16 j;
    s16 k;
    s16 vtx_x;
    s16 vtx_y;

    pauseCtx->offsetY = 0;

    if ((pauseCtx->state == PAUSE_STATE_OPENING_3) || (pauseCtx->state == PAUSE_STATE_OWL_WARP_3) ||
        (pauseCtx->state >= PAUSE_STATE_OWL_WARP_6) ||
        ((pauseCtx->state == PAUSE_STATE_SAVEPROMPT) && ((pauseCtx->savePromptState == PAUSE_SAVEPROMPT_STATE_3) ||
                                                         (pauseCtx->savePromptState == PAUSE_SAVEPROMPT_STATE_7)))) {
        pauseCtx->offsetY = 80;
    }

    if (pauseCtx->pageIndex != PAUSE_QUEST) {
        pauseCtx->itemPageVtx = GRAPH_ALLOC(gfxCtx, ((PAGE_BG_QUADS + VTX_PAGE_ITEM_QUADS) * 4) * sizeof(Vtx));
        KaleidoScope_SetPageVertices(play, pauseCtx->itemPageVtx, VTX_PAGE_ITEM, VTX_PAGE_ITEM_QUADS);

        pauseCtx->itemVtx = GRAPH_ALLOC(gfxCtx, (QUAD_ITEM_MAX * 4) * sizeof(Vtx));

        

        
        for (k = 0, i = 0, vtx_y = (ITEM_GRID_ROWS * ITEM_GRID_CELL_HEIGHT) / 2 - 6; k < ITEM_GRID_ROWS;
             k++, vtx_y -= ITEM_GRID_CELL_HEIGHT) {
            
            for (vtx_x = 0 - (ITEM_GRID_COLS * ITEM_GRID_CELL_WIDTH) / 2, j = 0; j < ITEM_GRID_COLS;
                 j++, i += 4, vtx_x += ITEM_GRID_CELL_WIDTH) {
                pauseCtx->itemVtx[i + 0].v.ob[0] = pauseCtx->itemVtx[i + 2].v.ob[0] = vtx_x + ITEM_GRID_QUAD_MARGIN;
                pauseCtx->itemVtx[i + 1].v.ob[0] = pauseCtx->itemVtx[i + 3].v.ob[0] =
                    pauseCtx->itemVtx[i + 0].v.ob[0] + ITEM_GRID_QUAD_WIDTH;

                pauseCtx->itemVtx[i + 0].v.ob[1] = pauseCtx->itemVtx[i + 1].v.ob[1] =
                    vtx_y + pauseCtx->offsetY - ITEM_GRID_QUAD_MARGIN;
                pauseCtx->itemVtx[i + 2].v.ob[1] = pauseCtx->itemVtx[i + 3].v.ob[1] =
                    pauseCtx->itemVtx[i + 0].v.ob[1] - ITEM_GRID_QUAD_WIDTH;

                pauseCtx->itemVtx[i + 0].v.ob[2] = pauseCtx->itemVtx[i + 1].v.ob[2] = pauseCtx->itemVtx[i + 2].v.ob[2] =
                    pauseCtx->itemVtx[i + 3].v.ob[2] = 0;

                pauseCtx->itemVtx[i + 0].v.flag = pauseCtx->itemVtx[i + 1].v.flag = pauseCtx->itemVtx[i + 2].v.flag =
                    pauseCtx->itemVtx[i + 3].v.flag = 0;

                pauseCtx->itemVtx[i + 0].v.tc[0] = pauseCtx->itemVtx[i + 0].v.tc[1] = pauseCtx->itemVtx[i + 1].v.tc[1] =
                    pauseCtx->itemVtx[i + 2].v.tc[0] = 0;

                pauseCtx->itemVtx[i + 1].v.tc[0] = pauseCtx->itemVtx[i + 2].v.tc[1] = pauseCtx->itemVtx[i + 3].v.tc[0] =
                    pauseCtx->itemVtx[i + 3].v.tc[1] = ITEM_GRID_QUAD_TEX_SIZE * (1 << 5);

                pauseCtx->itemVtx[i + 0].v.cn[0] = pauseCtx->itemVtx[i + 1].v.cn[0] = pauseCtx->itemVtx[i + 2].v.cn[0] =
                    pauseCtx->itemVtx[i + 3].v.cn[0] = pauseCtx->itemVtx[i + 0].v.cn[1] =
                        pauseCtx->itemVtx[i + 1].v.cn[1] = pauseCtx->itemVtx[i + 2].v.cn[1] =
                            pauseCtx->itemVtx[i + 3].v.cn[1] = pauseCtx->itemVtx[i + 0].v.cn[2] =
                                pauseCtx->itemVtx[i + 1].v.cn[2] = pauseCtx->itemVtx[i + 2].v.cn[2] =
                                    pauseCtx->itemVtx[i + 3].v.cn[2] = 255;

                pauseCtx->itemVtx[i + 0].v.cn[3] = pauseCtx->itemVtx[i + 1].v.cn[3] = pauseCtx->itemVtx[i + 2].v.cn[3] =
                    pauseCtx->itemVtx[i + 3].v.cn[3] = 255;
            }
        }

        

        for (j = EQUIP_SLOT_C_LEFT; j <= EQUIP_SLOT_C_RIGHT; j++, i += 4) {
            if (GET_CUR_FORM_BTN_SLOT(j) != ITEM_NONE) {
                k = GET_CUR_FORM_BTN_SLOT(j) * 4;

                pauseCtx->itemVtx[i + 0].v.ob[0] = pauseCtx->itemVtx[i + 2].v.ob[0] =
                    pauseCtx->itemVtx[k].v.ob[0] + ITEM_GRID_SELECTED_QUAD_MARGIN;

                pauseCtx->itemVtx[i + 1].v.ob[0] = pauseCtx->itemVtx[i + 3].v.ob[0] =
                    pauseCtx->itemVtx[i + 0].v.ob[0] + ITEM_GRID_SELECTED_QUAD_WIDTH;

                pauseCtx->itemVtx[i + 0].v.ob[1] = pauseCtx->itemVtx[i + 1].v.ob[1] =
                    pauseCtx->itemVtx[k].v.ob[1] - ITEM_GRID_SELECTED_QUAD_MARGIN;

                pauseCtx->itemVtx[i + 2].v.ob[1] = pauseCtx->itemVtx[i + 3].v.ob[1] =
                    pauseCtx->itemVtx[i + 0].v.ob[1] - ITEM_GRID_SELECTED_QUAD_WIDTH;

                pauseCtx->itemVtx[i + 0].v.ob[2] = pauseCtx->itemVtx[i + 1].v.ob[2] = pauseCtx->itemVtx[i + 2].v.ob[2] =
                    pauseCtx->itemVtx[i + 3].v.ob[2] = 0;

                pauseCtx->itemVtx[i + 0].v.flag = pauseCtx->itemVtx[i + 1].v.flag = pauseCtx->itemVtx[i + 2].v.flag =
                    pauseCtx->itemVtx[i + 3].v.flag = 0;

                pauseCtx->itemVtx[i + 0].v.tc[0] = pauseCtx->itemVtx[i + 0].v.tc[1] = pauseCtx->itemVtx[i + 1].v.tc[1] =
                    pauseCtx->itemVtx[i + 2].v.tc[0] = 0;

                pauseCtx->itemVtx[i + 1].v.tc[0] = pauseCtx->itemVtx[i + 2].v.tc[1] = pauseCtx->itemVtx[i + 3].v.tc[0] =
                    pauseCtx->itemVtx[i + 3].v.tc[1] = ITEM_GRID_SELECTED_QUAD_TEX_SIZE * (1 << 5);

                pauseCtx->itemVtx[i + 0].v.cn[0] = pauseCtx->itemVtx[i + 1].v.cn[0] = pauseCtx->itemVtx[i + 2].v.cn[0] =
                    pauseCtx->itemVtx[i + 3].v.cn[0] = pauseCtx->itemVtx[i + 0].v.cn[1] =
                        pauseCtx->itemVtx[i + 1].v.cn[1] = pauseCtx->itemVtx[i + 2].v.cn[1] =
                            pauseCtx->itemVtx[i + 3].v.cn[1] = pauseCtx->itemVtx[i + 0].v.cn[2] =
                                pauseCtx->itemVtx[i + 1].v.cn[2] = pauseCtx->itemVtx[i + 2].v.cn[2] =
                                    pauseCtx->itemVtx[i + 3].v.cn[2] = 255;

                pauseCtx->itemVtx[i + 0].v.cn[3] = pauseCtx->itemVtx[i + 1].v.cn[3] = pauseCtx->itemVtx[i + 2].v.cn[3] =
                    pauseCtx->itemVtx[i + 3].v.cn[3] = pauseCtx->alpha;
            } else {
                

                pauseCtx->itemVtx[i + 2].v.ob[0] = -300;
                pauseCtx->itemVtx[i + 0].v.ob[0] = pauseCtx->itemVtx[i + 2].v.ob[0];

                pauseCtx->itemVtx[i + 1].v.ob[0] = pauseCtx->itemVtx[i + 3].v.ob[0] =
                    pauseCtx->itemVtx[i + 0].v.ob[0] + ITEM_GRID_SELECTED_QUAD_WIDTH;

                pauseCtx->itemVtx[i + 0].v.ob[1] = pauseCtx->itemVtx[i + 1].v.ob[1] = 300;
                pauseCtx->itemVtx[i + 2].v.ob[1] = pauseCtx->itemVtx[i + 3].v.ob[1] =
                    pauseCtx->itemVtx[i + 0].v.ob[1] - ITEM_GRID_SELECTED_QUAD_HEIGHT;
            }
        }
    }

    if (pauseCtx->pageIndex != PAUSE_MASK) {
        if (!sInDungeonScene) {
            pauseCtx->mapPageVtx = GRAPH_ALLOC(
                gfxCtx, ((PAGE_BG_QUADS + VTX_PAGE_MAP_WORLD_QUADS + WORLD_MAP_IMAGE_FRAG_NUM) * 4) * sizeof(Vtx));
            j = KaleidoScope_SetPageVertices(play, pauseCtx->mapPageVtx, VTX_PAGE_MAP_WORLD, VTX_PAGE_MAP_WORLD_QUADS);

            for (i = 0, vtx_y = 59; i < WORLD_MAP_IMAGE_FRAG_NUM; i++, j += 4, vtx_y -= WORLD_MAP_IMAGE_FRAG_HEIGHT) {
                pauseCtx->mapPageVtx[j + 2].v.ob[0] = 0 - (WORLD_MAP_IMAGE_WIDTH / 2) - 1;
                pauseCtx->mapPageVtx[j + 0].v.ob[0] = pauseCtx->mapPageVtx[j + 2].v.ob[0];

                pauseCtx->mapPageVtx[j + 1].v.ob[0] = pauseCtx->mapPageVtx[j + 3].v.ob[0] =
                    pauseCtx->mapPageVtx[j + 0].v.ob[0] + WORLD_MAP_IMAGE_WIDTH;

                pauseCtx->mapPageVtx[j + 0].v.ob[1] = pauseCtx->mapPageVtx[j + 1].v.ob[1] = vtx_y + pauseCtx->offsetY;

                pauseCtx->mapPageVtx[j + 2].v.ob[1] = pauseCtx->mapPageVtx[j + 3].v.ob[1] =
                    pauseCtx->mapPageVtx[j + 0].v.ob[1] - WORLD_MAP_IMAGE_FRAG_HEIGHT;

                pauseCtx->mapPageVtx[j + 0].v.ob[2] = pauseCtx->mapPageVtx[j + 1].v.ob[2] =
                    pauseCtx->mapPageVtx[j + 2].v.ob[2] = pauseCtx->mapPageVtx[j + 3].v.ob[2] = 0;

                pauseCtx->mapPageVtx[j + 0].v.flag = pauseCtx->mapPageVtx[j + 1].v.flag =
                    pauseCtx->mapPageVtx[j + 2].v.flag = pauseCtx->mapPageVtx[j + 3].v.flag = 0;

                pauseCtx->mapPageVtx[j + 0].v.tc[0] = pauseCtx->mapPageVtx[j + 0].v.tc[1] =
                    pauseCtx->mapPageVtx[j + 1].v.tc[1] = pauseCtx->mapPageVtx[j + 2].v.tc[0] = 0;

                pauseCtx->mapPageVtx[j + 1].v.tc[0] = pauseCtx->mapPageVtx[j + 3].v.tc[0] =
                    WORLD_MAP_IMAGE_WIDTH * (1 << 5);
                pauseCtx->mapPageVtx[j + 2].v.tc[1] = pauseCtx->mapPageVtx[j + 3].v.tc[1] =
                    WORLD_MAP_IMAGE_FRAG_HEIGHT * (1 << 5);

                pauseCtx->mapPageVtx[j + 0].v.cn[0] = pauseCtx->mapPageVtx[j + 2].v.cn[0] =
                    pauseCtx->mapPageVtx[j + 0].v.cn[1] = pauseCtx->mapPageVtx[j + 2].v.cn[1] =
                        pauseCtx->mapPageVtx[j + 0].v.cn[2] = pauseCtx->mapPageVtx[j + 2].v.cn[2] =
                            pauseCtx->mapPageVtx[j + 1].v.cn[0] = pauseCtx->mapPageVtx[j + 3].v.cn[0] =
                                pauseCtx->mapPageVtx[j + 1].v.cn[1] = pauseCtx->mapPageVtx[j + 3].v.cn[1] =
                                    pauseCtx->mapPageVtx[j + 1].v.cn[2] = pauseCtx->mapPageVtx[j + 3].v.cn[2] =
                                        pauseCtx->mapPageVtx[j + 0].v.cn[3] = pauseCtx->mapPageVtx[j + 2].v.cn[3] =
                                            pauseCtx->mapPageVtx[j + 1].v.cn[3] = pauseCtx->mapPageVtx[j + 3].v.cn[3] =
                                                pauseCtx->alpha;
            }

            pauseCtx->mapPageVtx[j - 2].v.ob[1] = pauseCtx->mapPageVtx[j - 1].v.ob[1] =
                pauseCtx->mapPageVtx[j - 4].v.ob[1] - (WORLD_MAP_IMAGE_HEIGHT % WORLD_MAP_IMAGE_FRAG_HEIGHT);

            pauseCtx->mapPageVtx[j - 2].v.tc[1] = pauseCtx->mapPageVtx[j - 1].v.tc[1] =
                (WORLD_MAP_IMAGE_HEIGHT % WORLD_MAP_IMAGE_FRAG_HEIGHT) * (1 << 5);

        } else {
            pauseCtx->mapPageVtx =
                GRAPH_ALLOC(gfxCtx, ((PAGE_BG_QUADS + VTX_PAGE_MAP_DUNGEON_QUADS) * 4) * sizeof(Vtx));
            KaleidoScope_SetPageVertices(play, pauseCtx->mapPageVtx, VTX_PAGE_MAP_DUNGEON, VTX_PAGE_MAP_DUNGEON_QUADS);
        }
    }

    if (pauseCtx->pageIndex != PAUSE_ITEM) {
        pauseCtx->questPageVtx = GRAPH_ALLOC(gfxCtx, ((PAGE_BG_QUADS + VTX_PAGE_QUEST_QUADS) * 4) * sizeof(Vtx));
        KaleidoScope_SetPageVertices(play, pauseCtx->questPageVtx, VTX_PAGE_QUEST, VTX_PAGE_QUEST_QUADS);

        pauseCtx->questVtx = GRAPH_ALLOC(gfxCtx, (39 * 4) * sizeof(Vtx));

        for (k = 0, j = 0; j < 39; j++, k += 4) {
            if (j <= QUEST_SWORD) {
                pauseCtx->questVtx[k + 0].v.ob[0] = pauseCtx->questVtx[k + 2].v.ob[0] = sQuestVtxRectLeft[j];

                pauseCtx->questVtx[k + 1].v.ob[0] = pauseCtx->questVtx[k + 3].v.ob[0] =
                    pauseCtx->questVtx[k + 0].v.ob[0] + sQuestVtxWidths[j];

                pauseCtx->questVtx[k + 0].v.ob[1] = pauseCtx->questVtx[k + 1].v.ob[1] =
                    sQuestVtxRectTop[j] + pauseCtx->offsetY;

                pauseCtx->questVtx[k + 2].v.ob[1] = pauseCtx->questVtx[k + 3].v.ob[1] =
                    pauseCtx->questVtx[k + 0].v.ob[1] - sQuestVtxHeights[j];
            } else {
                pauseCtx->questVtx[k + 0].v.ob[0] = pauseCtx->questVtx[k + 2].v.ob[0] = sQuestVtxRectLeft[j] + 2;

                pauseCtx->questVtx[k + 1].v.ob[0] = pauseCtx->questVtx[k + 3].v.ob[0] =
                    pauseCtx->questVtx[k + 0].v.ob[0] + sQuestVtxWidths[j] - 4;

                pauseCtx->questVtx[k + 0].v.ob[1] = pauseCtx->questVtx[k + 1].v.ob[1] =
                    sQuestVtxRectTop[j] + pauseCtx->offsetY - 2;

                pauseCtx->questVtx[k + 2].v.ob[1] = pauseCtx->questVtx[k + 3].v.ob[1] =
                    pauseCtx->questVtx[k + 0].v.ob[1] - sQuestVtxHeights[j] + 4;
            }

            pauseCtx->questVtx[k + 0].v.ob[2] = pauseCtx->questVtx[k + 1].v.ob[2] = pauseCtx->questVtx[k + 2].v.ob[2] =
                pauseCtx->questVtx[k + 3].v.ob[2] = 0;

            pauseCtx->questVtx[k + 0].v.flag = pauseCtx->questVtx[k + 1].v.flag = pauseCtx->questVtx[k + 2].v.flag =
                pauseCtx->questVtx[k + 3].v.flag = 0;

            pauseCtx->questVtx[k + 0].v.tc[0] = pauseCtx->questVtx[k + 0].v.tc[1] = pauseCtx->questVtx[k + 1].v.tc[1] =
                pauseCtx->questVtx[k + 2].v.tc[0] = 0;

            pauseCtx->questVtx[k + 1].v.tc[0] = pauseCtx->questVtx[k + 3].v.tc[0] = sQuestVtxWidths[j] << 5;
            pauseCtx->questVtx[k + 2].v.tc[1] = pauseCtx->questVtx[k + 3].v.tc[1] = sQuestVtxHeights[j] << 5;

            pauseCtx->questVtx[k + 0].v.cn[0] = pauseCtx->questVtx[k + 1].v.cn[0] = pauseCtx->questVtx[k + 2].v.cn[0] =
                pauseCtx->questVtx[k + 3].v.cn[0] = pauseCtx->questVtx[k + 0].v.cn[1] =
                    pauseCtx->questVtx[k + 1].v.cn[1] = pauseCtx->questVtx[k + 2].v.cn[1] =
                        pauseCtx->questVtx[k + 3].v.cn[1] = pauseCtx->questVtx[k + 0].v.cn[2] =
                            pauseCtx->questVtx[k + 1].v.cn[2] = pauseCtx->questVtx[k + 2].v.cn[2] =
                                pauseCtx->questVtx[k + 3].v.cn[2] = 255;

            pauseCtx->questVtx[k + 0].v.cn[3] = pauseCtx->questVtx[k + 1].v.cn[3] = pauseCtx->questVtx[k + 2].v.cn[3] =
                pauseCtx->questVtx[k + 3].v.cn[3] = pauseCtx->alpha;
        }
    }

    if (pauseCtx->pageIndex != PAUSE_MAP) {
        pauseCtx->maskPageVtx = GRAPH_ALLOC(gfxCtx, ((PAGE_BG_QUADS + VTX_PAGE_MASK_QUADS) * 4) * sizeof(Vtx));
        KaleidoScope_SetPageVertices(play, pauseCtx->maskPageVtx, VTX_PAGE_MASK, VTX_PAGE_MASK_QUADS);

        pauseCtx->maskVtx = GRAPH_ALLOC(gfxCtx, (QUAD_MASK_MAX * 4) * sizeof(Vtx));

        
        for (k = 0, i = 0, vtx_y = (MASK_GRID_ROWS * MASK_GRID_CELL_HEIGHT) / 2 - 6; k < MASK_GRID_ROWS;
             k++, vtx_y -= MASK_GRID_CELL_HEIGHT) {
            
            for (vtx_x = 0 - (MASK_GRID_COLS * MASK_GRID_CELL_WIDTH) / 2, j = 0; j < MASK_GRID_COLS;
                 j++, i += 4, vtx_x += MASK_GRID_CELL_WIDTH) {
                pauseCtx->maskVtx[i + 0].v.ob[0] = pauseCtx->maskVtx[i + 2].v.ob[0] = vtx_x + MASK_GRID_QUAD_MARGIN;
                pauseCtx->maskVtx[i + 1].v.ob[0] = pauseCtx->maskVtx[i + 3].v.ob[0] =
                    pauseCtx->maskVtx[i + 0].v.ob[0] + MASK_GRID_QUAD_WIDTH;

                pauseCtx->maskVtx[i + 0].v.ob[1] = pauseCtx->maskVtx[i + 1].v.ob[1] =
                    vtx_y + pauseCtx->offsetY - MASK_GRID_QUAD_MARGIN;
                pauseCtx->maskVtx[i + 2].v.ob[1] = pauseCtx->maskVtx[i + 3].v.ob[1] =
                    pauseCtx->maskVtx[i + 0].v.ob[1] - MASK_GRID_QUAD_HEIGHT;

                pauseCtx->maskVtx[i + 0].v.ob[2] = pauseCtx->maskVtx[i + 1].v.ob[2] = pauseCtx->maskVtx[i + 2].v.ob[2] =
                    pauseCtx->maskVtx[i + 3].v.ob[2] = 0;

                pauseCtx->maskVtx[i + 0].v.flag = pauseCtx->maskVtx[i + 1].v.flag = pauseCtx->maskVtx[i + 2].v.flag =
                    pauseCtx->maskVtx[i + 3].v.flag = 0;

                pauseCtx->maskVtx[i + 0].v.tc[0] = pauseCtx->maskVtx[i + 0].v.tc[1] = pauseCtx->maskVtx[i + 1].v.tc[1] =
                    pauseCtx->maskVtx[i + 2].v.tc[0] = 0;

                pauseCtx->maskVtx[i + 1].v.tc[0] = pauseCtx->maskVtx[i + 2].v.tc[1] = pauseCtx->maskVtx[i + 3].v.tc[0] =
                    pauseCtx->maskVtx[i + 3].v.tc[1] = MASK_GRID_QUAD_TEX_SIZE * (1 << 5);

                pauseCtx->maskVtx[i + 0].v.cn[0] = pauseCtx->maskVtx[i + 1].v.cn[0] = pauseCtx->maskVtx[i + 2].v.cn[0] =
                    pauseCtx->maskVtx[i + 3].v.cn[0] = pauseCtx->maskVtx[i + 0].v.cn[1] =
                        pauseCtx->maskVtx[i + 1].v.cn[1] = pauseCtx->maskVtx[i + 2].v.cn[1] =
                            pauseCtx->maskVtx[i + 3].v.cn[1] = pauseCtx->maskVtx[i + 0].v.cn[2] =
                                pauseCtx->maskVtx[i + 1].v.cn[2] = pauseCtx->maskVtx[i + 2].v.cn[2] =
                                    pauseCtx->maskVtx[i + 3].v.cn[2] = 255;

                pauseCtx->maskVtx[i + 0].v.cn[3] = pauseCtx->maskVtx[i + 1].v.cn[3] = pauseCtx->maskVtx[i + 2].v.cn[3] =
                    pauseCtx->maskVtx[i + 3].v.cn[3] = 255;
            }
        }

        

        for (j = EQUIP_SLOT_C_LEFT; j <= EQUIP_SLOT_C_RIGHT; j++, i += 4) {
            if (GET_CUR_FORM_BTN_SLOT(j) != ITEM_NONE) {
                k = (GET_CUR_FORM_BTN_SLOT(j) - ITEM_NUM_SLOTS) * 4;

                pauseCtx->maskVtx[i + 0].v.ob[0] = pauseCtx->maskVtx[i + 2].v.ob[0] =
                    pauseCtx->maskVtx[k].v.ob[0] + MASK_GRID_SELECTED_QUAD_MARGIN;

                pauseCtx->maskVtx[i + 1].v.ob[0] = pauseCtx->maskVtx[i + 3].v.ob[0] =
                    pauseCtx->maskVtx[i + 0].v.ob[0] + MASK_GRID_SELECTED_QUAD_WIDTH;

                pauseCtx->maskVtx[i + 0].v.ob[1] = pauseCtx->maskVtx[i + 1].v.ob[1] =
                    pauseCtx->maskVtx[k].v.ob[1] - MASK_GRID_SELECTED_QUAD_MARGIN;

                pauseCtx->maskVtx[i + 2].v.ob[1] = pauseCtx->maskVtx[i + 3].v.ob[1] =
                    pauseCtx->maskVtx[i + 0].v.ob[1] - MASK_GRID_SELECTED_QUAD_HEIGHT;

                pauseCtx->maskVtx[i + 0].v.ob[2] = pauseCtx->maskVtx[i + 1].v.ob[2] = pauseCtx->maskVtx[i + 2].v.ob[2] =
                    pauseCtx->maskVtx[i + 3].v.ob[2] = 0;

                pauseCtx->maskVtx[i + 0].v.flag = pauseCtx->maskVtx[i + 1].v.flag = pauseCtx->maskVtx[i + 2].v.flag =
                    pauseCtx->maskVtx[i + 3].v.flag = 0;

                pauseCtx->maskVtx[i + 0].v.tc[0] = pauseCtx->maskVtx[i + 0].v.tc[1] = pauseCtx->maskVtx[i + 1].v.tc[1] =
                    pauseCtx->maskVtx[i + 2].v.tc[0] = 0;

                pauseCtx->maskVtx[i + 1].v.tc[0] = pauseCtx->maskVtx[i + 2].v.tc[1] = pauseCtx->maskVtx[i + 3].v.tc[0] =
                    pauseCtx->maskVtx[i + 3].v.tc[1] = MASK_GRID_SELECTED_QUAD_TEX_SIZE * (1 << 5);

                pauseCtx->maskVtx[i + 0].v.cn[0] = pauseCtx->maskVtx[i + 1].v.cn[0] = pauseCtx->maskVtx[i + 2].v.cn[0] =
                    pauseCtx->maskVtx[i + 3].v.cn[0] = pauseCtx->maskVtx[i + 0].v.cn[1] =
                        pauseCtx->maskVtx[i + 1].v.cn[1] = pauseCtx->maskVtx[i + 2].v.cn[1] =
                            pauseCtx->maskVtx[i + 3].v.cn[1] = pauseCtx->maskVtx[i + 0].v.cn[2] =
                                pauseCtx->maskVtx[i + 1].v.cn[2] = pauseCtx->maskVtx[i + 2].v.cn[2] =
                                    pauseCtx->maskVtx[i + 3].v.cn[2] = 255;

                pauseCtx->maskVtx[i + 0].v.cn[3] = pauseCtx->maskVtx[i + 1].v.cn[3] = pauseCtx->maskVtx[i + 2].v.cn[3] =
                    pauseCtx->maskVtx[i + 3].v.cn[3] = pauseCtx->alpha;
            } else {
                pauseCtx->maskVtx[i + 2].v.ob[0] = -300;
                pauseCtx->maskVtx[i + 0].v.ob[0] = pauseCtx->maskVtx[i + 2].v.ob[0];

                pauseCtx->maskVtx[i + 1].v.ob[0] = pauseCtx->maskVtx[i + 3].v.ob[0] =
                    pauseCtx->maskVtx[i + 0].v.ob[0] + MASK_GRID_SELECTED_QUAD_WIDTH;

                pauseCtx->maskVtx[i + 0].v.ob[1] = pauseCtx->maskVtx[i + 1].v.ob[1] = 300;
                pauseCtx->maskVtx[i + 2].v.ob[1] = pauseCtx->maskVtx[i + 3].v.ob[1] =
                    pauseCtx->maskVtx[i + 0].v.ob[1] - MASK_GRID_SELECTED_QUAD_HEIGHT;
            }
        }
    }

    pauseCtx->cursorVtx = GRAPH_ALLOC(play->state.gfxCtx, (PAUSE_QUAD_CURSOR_MAX * 4) * sizeof(Vtx));

    for (i = 0; i < (PAUSE_QUAD_CURSOR_MAX * 4); i++) {
        pauseCtx->cursorVtx[i].v.ob[0] = pauseCtx->cursorVtx[i].v.ob[1] = pauseCtx->cursorVtx[i].v.ob[2] = 0;

        pauseCtx->cursorVtx[i].v.flag = 0;

        pauseCtx->cursorVtx[i].v.tc[0] = pauseCtx->cursorVtx[i].v.tc[1] = 0;

        pauseCtx->cursorVtx[i].v.cn[0] = pauseCtx->cursorVtx[i].v.cn[1] = pauseCtx->cursorVtx[i].v.cn[2] =
            pauseCtx->cursorVtx[i].v.cn[3] = 255;
    }

    
    pauseCtx->cursorVtx[1].v.tc[0] = pauseCtx->cursorVtx[2].v.tc[1] = pauseCtx->cursorVtx[3].v.tc[0] =
        pauseCtx->cursorVtx[3].v.tc[1]
        
        = pauseCtx->cursorVtx[5].v.tc[0] = pauseCtx->cursorVtx[6].v.tc[1] = pauseCtx->cursorVtx[7].v.tc[0] =
            pauseCtx->cursorVtx[7].v.tc[1]
        
        = pauseCtx->cursorVtx[9].v.tc[0] = pauseCtx->cursorVtx[10].v.tc[1] = pauseCtx->cursorVtx[11].v.tc[0] =
            pauseCtx->cursorVtx[11].v.tc[1]
        
        = pauseCtx->cursorVtx[13].v.tc[0] = pauseCtx->cursorVtx[14].v.tc[1] = pauseCtx->cursorVtx[15].v.tc[0] =
            pauseCtx->cursorVtx[15].v.tc[1] = 16 * (1 << 5);

    
    pauseCtx->cursorVtx[17].v.tc[0] = pauseCtx->cursorVtx[18].v.tc[1] = pauseCtx->cursorVtx[19].v.tc[0] =
        pauseCtx->cursorVtx[19].v.tc[1] = 32 * (1 << 5);

    pauseCtx->infoPanelVtx = GRAPH_ALLOC(gfxCtx, 28 * sizeof(Vtx));

    if ((pauseCtx->state == PAUSE_STATE_SAVEPROMPT) || IS_PAUSE_STATE_GAMEOVER(pauseCtx)) {
        pauseCtx->promptPageVtx = GRAPH_ALLOC(gfxCtx, ((PAGE_BG_QUADS + VTX_PAGE_SAVE_QUADS) * 4) * sizeof(Vtx));
        KaleidoScope_SetPageVertices(play, pauseCtx->promptPageVtx, VTX_PAGE_PROMPT, VTX_PAGE_SAVE_QUADS);
    }
}
