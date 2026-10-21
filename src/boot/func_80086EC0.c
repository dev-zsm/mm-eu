// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0F0;
void Arena_Free(s32 *p, s32 n);

void func_80086EC0(s32 arg0) {
    Arena_Free(&D_8009D0F0, arg0);
}
