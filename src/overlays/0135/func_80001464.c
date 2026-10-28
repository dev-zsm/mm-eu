// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80133EDC(s32 *, s32, s32, M2C_UNK, s32, s32); /* extern */
extern s16 D_80900850;

void func_80001464(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_80133EDC(arg1, M2C_FIELD(arg0, s32 *, 0x1A8), M2C_FIELD(arg0, s32 *, 0x1C4), 0, 0, 0);
    D_80900850 = 0;
}
