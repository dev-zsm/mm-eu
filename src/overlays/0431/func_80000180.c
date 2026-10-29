#include "types.h"
typedef struct { u8 pad[0x190]; u8 unk190; } A;
extern void func_80137C80();
void func_80000180(A *a0, s32 a1) { func_80137C80(&a0->unk190, a1); }
