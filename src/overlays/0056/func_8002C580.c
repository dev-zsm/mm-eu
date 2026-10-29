#include "types.h"
typedef struct { u8 pad[0x14B]; u8 unk14B; } A;
extern u8 D_801E6F10;
void func_8002C580(s32 a0, A *a1, s32 a2) { if (a1->unk14B != 3) { D_801E6F10 = 3; } }
