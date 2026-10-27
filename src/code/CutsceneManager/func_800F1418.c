#include "types.h"

extern u8 D_801EC690[16];

void CutsceneManager_ClearNextCutscenes(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_801EC690[i] = 0;
    }
}
