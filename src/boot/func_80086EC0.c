// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0F0;
void func_80087634(s32 *p, s32 n);

void func_80086EC0(s32 arg0) {
    func_80087634(&D_8009D0F0, arg0);
}
