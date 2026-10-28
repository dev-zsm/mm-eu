// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 D_8009D0F0;
void __osMallocInit(s32 *p, s32 a, s32 b);

void MallocInit(s32 arg0, s32 arg1) {
    __osMallocInit(&D_8009D0F0, arg0, arg1);
}
