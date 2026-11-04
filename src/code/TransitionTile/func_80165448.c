// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo.h"

TransitionTile* TransitionTile_Init(TransitionTile* this, s32 cols, s32 rows) {
    s32 gridSize;

    bzero(this, sizeof(TransitionTile));
    this->frame = 0;
    this->cols = cols;
    this->rows = rows;
    gridSize = (cols + 1) * (rows + 1);
    this->vtxData = malloc(gridSize * sizeof(TransitionTileVtxData));
    this->vtxFrame1 = malloc(gridSize * sizeof(Vtx));
    this->vtxFrame2 = malloc(gridSize * sizeof(Vtx));
    this->gfx = malloc(((cols * 9 + 1) * rows + 2) * sizeof(Gfx));

    if ((this->vtxData == NULL) || (this->vtxFrame1 == NULL) || (this->vtxFrame2 == NULL) || (this->gfx == NULL)) {
        if (this->vtxData != NULL) {
            free(this->vtxData);
            this->vtxData = NULL;
        }
        if (this->vtxFrame1 != NULL) {
            free(this->vtxFrame1);
            this->vtxFrame1 = NULL;
        }
        if (this->vtxFrame2 != NULL) {
            free(this->vtxFrame2);
            this->vtxFrame2 = NULL;
        }
        if (this->gfx != NULL) {
            free(this->gfx);
            this->gfx = NULL;
        }
        return NULL;
    }

    TransitionTile_InitGraphics(this);
    TransitionTile_InitVtxData(this);
    this->frame = 0;

    return this;
}
