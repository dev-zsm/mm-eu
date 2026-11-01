#include "types.h"
typedef struct { u8 pad0[0xA4]; s16 unkA4; } A;
extern s16 D_801BE5D8;
extern s16 D_801BE5DA;
extern s16 D_801BE5DC;
extern s16 D_801BE5DE;
extern s16 D_801BE5E0;
extern s16 D_801BE5E2;
extern s16 D_801BE5E4;
extern s16 D_801BE5E6;
extern s32 D_801EAB9C;
s32 Horse_IsValidSceneLayer(A *arg0, s32 arg1) {
    if (D_801EAB9C == 0) {
        return 1;
    }
    if (D_801BE5D8 == arg0->unkA4 && D_801EAB9C == D_801BE5DA + 1) {
        return 1;
    }
    if (D_801BE5DC == arg0->unkA4 && D_801EAB9C == D_801BE5DE + 1) {
        return 1;
    }
    if (D_801BE5E0 == arg0->unkA4 && D_801EAB9C == D_801BE5E2 + 1) {
        return 1;
    }
    if (D_801BE5E4 == arg0->unkA4 && D_801EAB9C == D_801BE5E6 + 1) {
        return 1;
    }
    return 0;
}
