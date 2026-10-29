#include "types.h"
typedef struct { u8 pad[0x32]; s16 unk32; u8 pad34[0x5E]; s16 unk92; u8 pad94[0x2A]; s16 unkBE; u8 padC0[0x84]; void *unk144; } A;
extern u8 D_80A7C8CC[];
void func_800031F4(A *a0, s32 a1) { a0->unk32 = a0->unk92; a0->unkBE = a0->unk32; a0->unk144 = D_80A7C8CC; }
