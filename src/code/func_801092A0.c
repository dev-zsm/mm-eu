// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801BF890[];

typedef struct { u8 b[4]; } Color4;

void MapData_GetMapColor(s32 a0, void *a1) {
    *(Color4 *)a1 = ((Color4 *)D_801BF890)[a0];
}
