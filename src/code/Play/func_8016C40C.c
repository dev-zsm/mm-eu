// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play_hireso.h"

void BombersNotebook_DrawColumns(Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    s16* color;
    s32 i;
    s32 j;
    s32 k;
    s32 columnRectLeft;
    s32 subColumnRectLeft;
    s32 pad;

    gDPLoadTextureBlock_4b(gfx++, gBombersNotebookSubColumnBoxTex, G_IM_FMT_I, 48, 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    color = &sBombersNotebookColumnColors[0][0][0];
    for (i = 0, columnRectLeft = 120; i < ARRAY_COUNT(sBombersNotebookColumnColors); i++, columnRectLeft += 150) {
        subColumnRectLeft = columnRectLeft;
        for (j = 0; j < 2; j++) {
            gDPSetPrimColor(gfx++, 0, 0, color[0], color[1], color[2], 192);
            for (k = 0; k < 2; k++) {
                BombersNotebook_DrawScisTexRect(&gfx, subColumnRectLeft * 4, 104 * 4, (subColumnRectLeft + 48) * 4,
                                                480 * 4, 0, 0, 0, 1 << 10, 1 << 10);
                subColumnRectLeft += 36;
            }
            color += 3;
        }
    }

    gDPPipeSync(gfx++);
    *gfxP = gfx;
}
