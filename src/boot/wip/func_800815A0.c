// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void func_800942F0(void *a, u64 b, s32 c, s32 d, void *e, s32 f);
extern void func_8008D8B0(void);

void func_800815A0(u8 *arg0) {
    func_800942F0(arg0 + 0x258, 0x173EED8, 0, 0, arg0 + 0x60, 0x2A1);
    func_8008D8B0();
}
