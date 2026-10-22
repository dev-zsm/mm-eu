// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0F0;
void func_8008736C(s32 *p);

void MallocCleanup(void) {
    func_8008736C(&D_8009D0F0);
}
