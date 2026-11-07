// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_mask.h"

void KaleidoScope_DrawMaskSelect(PlayState* play) {
    PauseContext* pauseCtx = &play->pauseCtx;
    u16 i;
    u16 j;

    OPEN_DISPS(play->state.gfxCtx);

    KaleidoScope_SetCursorVtxPos(pauseCtx, pauseCtx->cursorSlot[PAUSE_MASK] * 4, pauseCtx->maskVtx);

    Gfx_SetupDL42_Opa(play->state.gfxCtx);

    
    
    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);
    for (i = 0, j = MASK_NUM_SLOTS * 4; i < 3; i++, j += 4) {
        if (GET_CUR_FORM_BTN_ITEM(i + 1) != ITEM_NONE) {
            if (GET_CUR_FORM_BTN_SLOT(i + 1) >= ITEM_NUM_SLOTS) {
                gSPVertex(POLY_OPA_DISP++, &pauseCtx->maskVtx[j], 4, 0);
                POLY_OPA_DISP = Gfx_DrawTexQuadIA8(POLY_OPA_DISP, gEquippedItemOutlineTex, 32, 32, 0);
            }
        }
    }

    gDPPipeSync(POLY_OPA_DISP++);

    
    
    gDPSetCombineMode(POLY_OPA_DISP++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    for (j = 0, i = 0; i < MASK_NUM_SLOTS; i++, j += 4) {
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, pauseCtx->alpha);

        if (((void)0, gSaveContext.save.saveInfo.inventory.items[i + ITEM_NUM_SLOTS]) != ITEM_NONE) {
            if (!CHECK_GIVEN_MASK_ON_MOON(i)) {
                if ((pauseCtx->mainState == PAUSE_MAIN_STATE_IDLE) && (pauseCtx->pageIndex == PAUSE_MASK) &&
                    (pauseCtx->cursorSpecialPos == 0) && gMaskPlayerFormSlotRestrictions[GET_PLAYER_FORM][i]) {
                    if ((sMaskEquipState == EQUIP_STATE_MAGIC_ARROW_HOVER_OVER_BOW_SLOT) && (i == SLOT_ARROW_ICE)) {
                        
                        
                        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0,
                                        sMaskMagicArrowEffectsR[pauseCtx->equipTargetItem - 0xB5],
                                        sMaskMagicArrowEffectsG[pauseCtx->equipTargetItem - 0xB5],
                                        sMaskMagicArrowEffectsB[pauseCtx->equipTargetItem - 0xB5], pauseCtx->alpha);

                        pauseCtx->maskVtx[j + 0].v.ob[0] = pauseCtx->maskVtx[j + 2].v.ob[0] =
                            pauseCtx->maskVtx[j + 0].v.ob[0] - 2;
                        pauseCtx->maskVtx[j + 1].v.ob[0] = pauseCtx->maskVtx[j + 3].v.ob[0] =
                            pauseCtx->maskVtx[j + 0].v.ob[0] + 32;
                        pauseCtx->maskVtx[j + 0].v.ob[1] = pauseCtx->maskVtx[j + 1].v.ob[1] =
                            pauseCtx->maskVtx[j + 0].v.ob[1] + 2;
                        pauseCtx->maskVtx[j + 2].v.ob[1] = pauseCtx->maskVtx[j + 3].v.ob[1] =
                            pauseCtx->maskVtx[j + 0].v.ob[1] - 32;

                    } else if (i == pauseCtx->cursorSlot[PAUSE_MASK]) {
                        
                        pauseCtx->maskVtx[j + 0].v.ob[0] = pauseCtx->maskVtx[j + 2].v.ob[0] =
                            pauseCtx->maskVtx[j + 0].v.ob[0] - 2;
                        pauseCtx->maskVtx[j + 1].v.ob[0] = pauseCtx->maskVtx[j + 3].v.ob[0] =
                            pauseCtx->maskVtx[j + 0].v.ob[0] + 32;
                        pauseCtx->maskVtx[j + 0].v.ob[1] = pauseCtx->maskVtx[j + 1].v.ob[1] =
                            pauseCtx->maskVtx[j + 0].v.ob[1] + 2;
                        pauseCtx->maskVtx[j + 2].v.ob[1] = pauseCtx->maskVtx[j + 3].v.ob[1] =
                            pauseCtx->maskVtx[j + 0].v.ob[1] - 32;
                    }
                }

                gSPVertex(POLY_OPA_DISP++, &pauseCtx->maskVtx[j + 0], 4, 0);
                KaleidoScope_DrawTexQuadRGBA32(
                    play->state.gfxCtx,
                    gItemIcons[((void)0, gSaveContext.save.saveInfo.inventory.items[i + ITEM_NUM_SLOTS])], 32, 32, 0);
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
