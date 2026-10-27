// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 unk4;
    u8 unk5;
    u8 pad6[6];
} MapTexDim;

extern u8 D_801BF89C[];

void MapData_GetMapTexDimGameplayDangeonKeep(s32 arg0, s32 *arg1, s32 *arg2) {
    MapTexDim *e = (MapTexDim *)((u8 *)D_801BF89C + arg0 * 12);

    *arg1 = e->unk4;
    *arg2 = e->unk5;
}
