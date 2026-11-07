#include "types.h"
extern u8 D_80800768[];
typedef struct { u8 pad0[0xC]; u8 *unkC; s32 unk10; u8 pad14[0x87]; u8 unk9B; } S0;
void MapSelect_LoadConsoleLogo(S0 *a) {
    a->unk9B = 0;
    a->unk10 = 0x248;
    a->unkC = D_80800768;
}
