// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 D_8009D0F0;
void func_8008727C(s32 *p, s32 a, s32 b);

void func_80086F98(s32 arg0, s32 arg1) {
    func_8008727C(&D_8009D0F0, arg0, arg1);
}
