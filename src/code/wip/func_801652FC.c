// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { f32 x, y; } P;
typedef struct {
    s32 cols;
    s32 rows;
    u8 pad8[4];
    P *data;
} T;
void TransitionTile_InitVtxData(T *t) {
    s32 row;
    s32 col;
    for (row = 0; row < t->rows + 1; row++) {
        for (col = 0; col < t->cols + 1; col++) {
            t->data[row * (t->cols + 1) + col].x = col * 32;
            t->data[row * (t->cols + 1) + col].y = row * 32;
        }
    }
}
