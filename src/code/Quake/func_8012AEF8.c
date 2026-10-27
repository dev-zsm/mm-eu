#include "types.h"

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u8 pad_C[0x12];
    s16 unk1E;
    u8 pad20[4];
} QuakeRequest; // size = 0x24

extern QuakeRequest D_801ED280[4];
extern s16 D_801C1B80;
extern s16 D_801C1B84;

void Quake_Init(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        D_801ED280[i].unk8 = 0;
        D_801ED280[i].unk1E = 0;
    }
    D_801C1B80 = 1;
    D_801C1B84 = 0;
}
