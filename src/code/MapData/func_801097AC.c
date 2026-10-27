// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; } MapITex;

extern MapITex D_801BFCC0[];

void MapData_GetMapITexOffset(s32 arg0, s32 *arg1, s32 *arg2) {
    MapITex *temp_v0;

    temp_v0 = &D_801BFCC0[arg0];
    *arg1 = temp_v0->unk2;
    *arg2 = temp_v0->unk4;
}
