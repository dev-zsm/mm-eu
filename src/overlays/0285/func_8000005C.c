#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x45C]; u16 a45C; } T;
extern T *D_801EB7E0;
void func_8000005C(s32 a0, u8 a1) { D_801EB7E0->a45C = a1; }
