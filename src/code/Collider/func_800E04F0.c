#include "types.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; } ColDmgInfo;

extern u8 D_801BAD90;

s32 Collider_InitElementDamageInfoAC(s32 a0, ColDmgInfo *a1) {
    ColDmgInfo *src = (ColDmgInfo *)&D_801BAD90;
    *a1 = *src;
    return 1;
}
