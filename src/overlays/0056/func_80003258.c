// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

void func_8082EAEC();
void func_80124108();
void func_801379F0();
void func_808301E8();
extern u8 D_808481A4;

void func_80003258(s32 arg0, u8 *arg1) {
    func_8082EAEC(arg0, arg1, &D_808481A4);
    if (M2C_FIELD(arg1, s8 *, 0x14A) < 0) {
        func_80124108(arg1);
    }
    func_801379F0(arg1 + 0x284);
    func_808301E8(arg1);
}
