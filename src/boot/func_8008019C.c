// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_80000500[];
extern u8 D_8009B610[];
extern s32 D_80096CCC;

void func_80080180(u8 *p, s32 n, u32 v);
void func_8008B7F0(u8 *p);
void func_800922A0(s32 a);
void func_80090000(u8 *p);
void func_8008B010(s32 a);

void func_8008019C(void) {
    func_80080180(D_80000500, 0x25800, 0x10001);
    func_8008B7F0(D_8009B610);
    func_800922A0(D_80096CCC);
    func_80090000(D_80000500);
    func_8008B010(0);
}
