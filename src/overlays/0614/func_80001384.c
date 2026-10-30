// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_80BE42CC;
void func_80BE33FC();
void func_80001384(u8 *a) {
    func_80BE33FC(a);
    *(s16 *)(a + 0x2A0) = 4;
    *(u8 **)(a + 0x284) = &D_80BE42CC;
}
