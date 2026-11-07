// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_map.h"

void KaleidoScope_DrawDungeonStrayFairyCount(PlayState* play) {
    s16 counterDigits[2];
    s16 rectLeft;
    s16 digitIndex;

    OPEN_DISPS(play->state.gfxCtx);

    
    counterDigits[1] = STRAY_FAIRY_SCATTERED_TOTAL;
    counterDigits[0] = counterDigits[1] / 10;
    counterDigits[1] -= (s16)(counterDigits[0] * 10);

    
    for (rectLeft = 116, digitIndex = 0; digitIndex < 2; digitIndex++, rectLeft += 8) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 0, 0, 255);

        POLY_OPA_DISP = Gfx_DrawTexRectI8(POLY_OPA_DISP, (u8*)gCounterDigit0Tex + (8 * 16 * counterDigits[digitIndex]),
                                          8, 16, rectLeft + 1, 146, 8, 16, 1 << 10, 1 << 10);

        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);

        gSPTextureRectangle(POLY_OPA_DISP++, rectLeft * 4, 145 << 2, (rectLeft + 8) * 4, 161 << 2, G_TX_RENDERTILE, 0,
                            0, 1 << 10, 1 << 10);
    }

    
    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 0, 0, 255);

    POLY_OPA_DISP =
        Gfx_DrawTexRectI8(POLY_OPA_DISP, gStrayFairyMapCounterSlashTex, 8, 16, 107, 146, 8, 16, 1 << 10, 1 << 10);

    gDPPipeSync(POLY_OPA_DISP++);
    gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);

    gSPTextureRectangle(POLY_OPA_DISP++, 106 << 2, 145 << 2, 114 << 2, 161 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                        1 << 10);

    
    counterDigits[1] = gSaveContext.save.saveInfo.inventory.strayFairies[(void)0, gSaveContext.dungeonSceneSharedIndex];
    counterDigits[0] = counterDigits[1] / 10;
    counterDigits[1] -= (s16)(counterDigits[0] * 10);

    
    for (rectLeft = 88, digitIndex = 0; digitIndex < 2; digitIndex++, rectLeft += 8) {
        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 0, 0, 0, 255);

        POLY_OPA_DISP = Gfx_DrawTexRectI8(POLY_OPA_DISP, (u8*)gCounterDigit0Tex + (8 * 16 * counterDigits[digitIndex]),
                                          8, 16, rectLeft + 1, 146, 8, 16, 1 << 10, 1 << 10);

        gDPPipeSync(POLY_OPA_DISP++);
        gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, 255, 255, 255, 255);

        gSPTextureRectangle(POLY_OPA_DISP++, rectLeft * 4, 145 << 2, (rectLeft + 8) * 4, 161 << 2, G_TX_RENDERTILE, 0,
                            0, 1 << 10, 1 << 10);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
