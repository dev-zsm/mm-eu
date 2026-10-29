#include "types.h"

extern struct {
    u8 pad0[0x40];
    s16 count;
    u8 pad42[6];
    s16 *heights;
} D_801BF708;

f32 MapDisp_GetStoreyY(f32 posY) {
    s32 i;
    f32 y;

    y = D_801BF708.heights[D_801BF708.count - 1];
    if (y - 80.0f < posY) {
        return y;
    }
    for (i = D_801BF708.count - 2; i >= 0; i--) {
        y = D_801BF708.heights[i];
        if (y - 80.0f < posY && posY < D_801BF708.heights[i + 1] + 80.0f) {
            return y;
        }
    }
    y = D_801BF708.heights[0];
    if (posY < y + 80.0f) {
        return y;
    }
    return 0.0f;
}
