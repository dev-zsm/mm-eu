// FLAGS: -O2 -g0 -mips2
#include "types.h"
void func_80917B04();
void func_80917E94();
void func_80000ED8(u8 *a0, s32 a1) {
    func_80917B04(a0);
    if (*(s16 *)(a0 + 0xBCA) == 0) {
        func_80917E94(a0);
    }
}
