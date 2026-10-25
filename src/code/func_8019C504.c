#include "types.h"

extern u8 D_801CF950[8];
extern u8 D_801CF958;

void AudioOcarina_UpdateCurOcarinaSong(void) {
    u8 i;

    if (D_801CF958 == 8) {
        for (i = 0; i < 7; i++) {
            D_801CF950[i] = D_801CF950[i + 1];
        }
    } else {
        D_801CF958++;
    }
}
