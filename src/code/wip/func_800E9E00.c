#include "types.h"

typedef struct {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[3];
    f32 unkC;
    s16 unk10;
} Struct_800E9E00;

extern s16 D_801EC648;
extern s16 D_801EC64A;
extern s16 D_801EC64C[8];
extern u8 D_801EC660;
void Audio_SetCutsceneFlag(s32);

void func_800E9E00(u8 *arg0, Struct_800E9E00 *arg1) {
    s32 i;

    arg1->unk8 = 0;
    arg1->unk10 = 0;
    arg1->unkC = 0.0f;
    arg0[0x1F24] = 0;
    *(s16 *)(arg0 + 0x1F36) = 0;
    D_801EC648 = 0;
    D_801EC64A = 0;
    for (i = 0; i < 8; i++) {
        D_801EC64C[i] = 0;
    }
    D_801EC660 = 0;
    Audio_SetCutsceneFlag(0);
}
