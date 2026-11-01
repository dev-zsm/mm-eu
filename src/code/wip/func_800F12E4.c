#include "types.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    u8 padC[4];
    s32 unk10;
    u8 pad14[2];
    s16 unk16;
} CsState;

extern s32 D_801EC670;
extern s16 D_801EC674;
extern u8 D_801EC678[];
extern u8 D_801EC690[];
extern CsState D_801BE3E0;

void CutsceneManager_Init(s32 a0, s32 a1, s16 a2) {
    s32 i;

    D_801EC670 = a1;
    D_801EC674 = a2;
    for (i = 0; i < 0x10; i++) {
        D_801EC690[i] = 0;
        D_801EC678[i] = 0;
    }
    D_801BE3E0.unk4 = -1;
    D_801BE3E0.unk0 = D_801BE3E0.unk4;
    D_801BE3E0.unk10 = a0;
    D_801BE3E0.unk2 = -1;
    D_801BE3E0.unk8 = 0;
    D_801BE3E0.unk6 = 0;
    D_801BE3E0.unk16 = 0;
}
