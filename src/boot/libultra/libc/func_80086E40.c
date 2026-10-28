// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0F0;
void func_8008743C(s32 *p, s32 n);

void malloc(s32 arg0) {
    func_8008743C(&D_8009D0F0, arg0);
}
