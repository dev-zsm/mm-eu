// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0F0;
void func_8008795C(s32 *p);

void CheckArena(void) {
    func_8008795C(&D_8009D0F0);
}
