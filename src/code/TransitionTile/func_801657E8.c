// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo.h"

void TransitionTile_Suck(TransitionTile* this) {
    s32 row;
    s32 col;
    f32 diffX;
    f32 diffY;
    f32 scale;

    for (row = 0; row < this->rows + 1; row++) {
        for (col = 0; col < this->cols + 1; col++) {
            diffX = (this->vtxData + col + row * (this->cols + 1))->x - (this->vtxData + 5 + 4 * (this->cols + 1))->x;
            diffY = (this->vtxData + col + row * (this->cols + 1))->y - (this->vtxData + 5 + 4 * (this->cols + 1))->y;
            scale = (SQ(diffX) + SQ(diffY)) / SQ(10.0f);
            if (scale != 0.0f) {
                if (scale < 1.0f) {
                    scale = 1.0f;
                }
                (this->vtxData + col + row * (this->cols + 1))->x -= diffX / scale;
                (this->vtxData + col + row * (this->cols + 1))->y -= diffY / scale;
            }
        }
    }
}
