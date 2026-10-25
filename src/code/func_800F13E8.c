#include "types.h"

extern u8 D_801EC678[4][4];

void CutsceneManager_ClearWaiting(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            D_801EC678[i][j] = 0;
        }
    }
}
