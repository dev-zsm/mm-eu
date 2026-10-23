// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 b[4]; u16 h; } C6;
void *Camera_GetCamDir(u8 *a0, u8 *a1) { *(C6 *)a0 = *(C6 *)(a1 + 0x13A); return a0; }
