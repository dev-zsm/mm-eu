#include "types.h"

typedef struct {
    u8 pad0[8];
    s32 isActive;
    u8 padC[0x12];
    s16 timer;
    u8 pad20[4];
} QuakeRequest;

extern QuakeRequest D_801ED280[4];

s16 Quake_GetFreeIndex(void) {
    s32 i;
    s32 index = 0;
    s32 minTimer = 0x10000;

    for (i = 0; i < 4; i++) {
        if (D_801ED280[i].isActive == 0) {
            index = i;
            break;
        }
        if (D_801ED280[i].timer < minTimer) {
            minTimer = D_801ED280[i].timer;
            index = i;
        }
    }
    return index;
}
