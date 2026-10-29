#include "types.h"

extern void func_80B5FEA8();
extern void func_80137070();

void func_80003778(u8 *a0, s32 a1) {
    func_80B5FEA8(a0, a1, 2);
    func_80137070(a0 + 0x160);
}
