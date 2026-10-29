#include "types.h"
typedef struct { u8 pad[0x32]; s16 unk32; u8 pad34[0x5E]; s16 unk92; u8 pad94[0x16C]; void *unk200; } A;
extern u8 D_80B47560[];
void func_80001234(A *a0) { a0->unk32 = a0->unk92; a0->unk200 = D_80B47560; }
