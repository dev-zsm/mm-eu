#include "types.h"
#include "generated/code_funcs.h"

typedef struct { u8 pad[0x4C8]; } EffA;
typedef struct { u8 pad[0x1B0]; } EffB;
typedef struct { u8 pad[0x610]; } EffC;

extern s32 D_801DB840;
extern EffA D_801DB844[3];
extern EffB D_801DC69C[25];
extern EffC D_801DF630[15];

void Effect_Init(struct PlayState *play) {
    s32 i;

    for (i = 0; i < 3; i++) {
        Effect_InitStatus(&D_801DB844[i]);
    }
    for (i = 0; i < 25; i++) {
        Effect_InitStatus(&D_801DC69C[i]);
    }
    for (i = 0; i < 3; i++) {
        Effect_InitStatus(&D_801DC69C[i]);
    }
    for (i = 0; i < 15; i++) {
        Effect_InitStatus(&D_801DF630[i]);
    }
    D_801DB840 = play;
}
