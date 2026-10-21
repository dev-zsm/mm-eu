// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80089E5C(u8 *dst, s32 src);

void func_8008D94C(s32 a0) {
    u8 buf;

    func_80089E5C(&buf, a0);
}
