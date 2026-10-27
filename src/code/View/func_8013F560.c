// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { s32 x; s32 y; s32 z; s32 w; } Vec4;
void View_GetViewport(s32 *a0, s32 *a1) {
    *(Vec4 *)a1 = *(Vec4 *)&a0[2];
}
