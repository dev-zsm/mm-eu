#include "types.h"
typedef struct { u8 pad[0x2EC]; void *unk2EC; } A;
extern s32 D_80B33670;
extern u8 D_80B2BCD8[];
void func_800035D8(A *a) {
    D_80B33670 = 2;
    a->unk2EC = D_80B2BCD8;
}
