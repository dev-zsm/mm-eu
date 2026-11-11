// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

void func_8082D240();
s32 func_80123E10(u8 *, s8);
void func_80123F54();
extern s32 D_8085C86C[];

void func_8002C800(s32 arg0, u8 *arg1, s32 arg2) {
    func_8082D240(arg0, arg1, D_8085C86C[M2C_FIELD(arg1, u8 *, 0x14B)]);
    M2C_FIELD(arg1, s8 *, 0x14A) = 0x14;
    func_80123F54(arg1, func_80123E10(arg1, M2C_FIELD(arg1, s8 *, 0x14A)));
}
