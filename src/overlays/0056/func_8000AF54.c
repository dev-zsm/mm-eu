// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80830E10();
void func_8082DB54();
void func_8082D184();
extern u8 D_400D0C8;
extern u8 D_808551E8;

void func_8000AF54(s32 arg0, u8 *arg1) {
    func_80830E10(arg0, arg1, &D_808551E8, 0);
    func_8082DB54(arg0, arg1, &D_400D0C8);
    M2C_FIELD(arg1, s32 *, 0xA6C) |= 0x20000100;
    func_8082D184(arg1);
}
