// FLAGS: -O2 -g3 -mips2
#include "types.h"
void func_80A07A70();
void func_800002A4(s32 a, s32 b, u8 *c) {
    *(s16 *)(c + 0x44) = *(s16 *)(c + 0x46) + *(s16 *)(c + 0x44);
    func_80A07A70(c, a);
}
