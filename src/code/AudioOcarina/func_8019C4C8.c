#include "types.h"

extern u8 D_801CF8EC;
extern u8 D_801CF8F8;
extern u8 D_801F4CA2;

void AudioOcarina_CheckIfStartedSong(void) {
    if (D_801CF8EC != 0xFF) {
        if (D_801F4CA2 == 0) {
            D_801F4CA2 = 1;
            D_801CF8F8 = 0xFF;
        }
    }
}
