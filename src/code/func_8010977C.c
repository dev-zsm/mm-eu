#include "types.h"

typedef struct { u8 unk0; u8 unk1; u8 pad2[8]; } MapITexEntry;

extern u8 D_801BFCC0;

void MapData_GetMapITexDim(s32 a0, u32 *a1, u32 *a2) {
    MapITexEntry *e = (MapITexEntry *)&D_801BFCC0;
    *a1 = e[a0].unk0;
    *a2 = e[a0].unk1;
}
