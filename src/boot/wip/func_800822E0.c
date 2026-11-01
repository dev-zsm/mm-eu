// FLAGS: -O2 -g3 -mips2 -trapuv
// best attempt: 9 instr differ (ROM loads the word once: exponent in $v1, copy of the word in $v0 via 'or v0,a2,zero')
#include "types.h"

extern void func_8008198C();
extern u8 D_8009886C[];
extern u8 D_8009887C[];

void Fault_LogFReg(s32 arg0, f32 *arg1) {
    s32 bits;
    s32 exp;

    exp = (s32)((u32)(*(u32 *)arg1 & 0x7F800000) >> 23) - 0x7F;
    bits = *(s32 *)arg1;
    if ((exp >= -0x7E && exp < 0x80) || (s32)bits == 0) {
        func_8008198C(D_8009886C, arg0, (f64)*arg1);
        return;
    }
    func_8008198C(D_8009887C, arg0);
}
