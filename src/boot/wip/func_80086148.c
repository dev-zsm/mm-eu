// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80086128(s32 *a0);

void func_80086148(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80086128(&arg2);
}
