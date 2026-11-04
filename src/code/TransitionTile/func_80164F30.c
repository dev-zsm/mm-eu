// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo.h"

void TransitionTile_InitGraphics(TransitionTile* this) {
    s32 frame;
    s32 col;
    s32 col2;
    s32 colTex;
    Vtx* vtx;
    s32 row;
    s32 rowTex;
    Gfx* gfx;

    guMtxIdent(&this->modelView);
    guMtxIdent(&this->unk_98);
    guOrtho(&this->projection, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, -1000.0f, 1000.0f, 1.0f);

    for (frame = 0; frame < 2; frame++) {
        this->frame = frame;
        vtx = (this->frame == 0) ? this->vtxFrame1 : this->vtxFrame2;
        rowTex = 0;
        for (row = 0; row < (this->rows + 1); row++) {
            colTex = 0;
            for (col = 0; col < (this->cols + 1); col++) {
                SET_VERTEX(vtx++, col * 0x20, row * 0x20, -5, 0, colTex << 6, rowTex << 6, 0, 0, 120, 255);
                colTex += 0x20;
            }
            rowTex += 0x20;
        }
    }

    gfx = this->gfx;
    for (rowTex = 0, row = 0; row < this->rows; row++, rowTex += 0x20) {
        gSPVertex(gfx++, SEGMENT_ADDR(0xA, (u32)row * (this->cols + 1) * sizeof(Vtx)), 2 * (this->cols + 1), 0);

        colTex = 0;
        col2 = 0;
        col = 0;
        while (col < this->cols) {
            gDPPipeSync(gfx++);

            gDPLoadTextureTile(gfx++, SEGMENT_ADDR(0xB, 0), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, SCREEN_HEIGHT,
                               colTex, rowTex, colTex + 0x20, rowTex + 0x20, 0, G_TX_NOMIRROR | G_TX_WRAP,
                               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSP1Quadrangle(gfx++, col, col + 1, col2 + this->cols + 2, this->cols + col2 + 1, 0);

            colTex += 0x20;
            col2++;
            col++;
        }
    }

    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
}
