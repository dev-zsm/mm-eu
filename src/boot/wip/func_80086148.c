// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80086128(s32 a, s32 b, s32 *c);

/* only missing: sw a1,36(sp) spill */
void func_80086148(s32 a0, s32 a1, s32 a2, ...) {
    func_80086128(a0, a1, &a2);
}
