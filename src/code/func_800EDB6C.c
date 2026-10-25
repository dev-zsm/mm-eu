#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x1F28];
    /* 0x1F28 */ s32 unk1F28;
    /* 0x1F2C */ u8 pad1F2C[0x1F36 - 0x1F2C];
    /* 0x1F36 */ s16 unk1F36;
    /* 0x1F38 */ u8 pad1F38[0x1F74 - 0x1F38];
    /* 0x1F74 */ s32 (*unk1F74)[2];
} PlayState;

typedef struct {
    /* 0x0000 */ u8 pad0[0x1452];
    /* 0x1452 */ s16 unk1452;
} GameData;

extern GameData *D_801EB7E0;
extern u8 D_801EAE3C;

s32 func_80100304(s32 arg0, u8 arg1, PlayState *play);

void Cutscene_StartScripted(PlayState *play, u8 index) {
    if (D_801EB7E0->unk1452 == 0) {
        play->unk1F36 = index;
        play->unk1F28 = func_80100304(play->unk1F74[index][0], index, play);
    }
    D_801EAE3C = 1;
}
