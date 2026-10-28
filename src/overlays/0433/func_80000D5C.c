// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012CA60(s32);                         /* extern */
M2C_UNK func_80134760(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80ACBA20;
extern M2C_UNK D_80ACBA70;
extern M2C_UNK D_80ACBAC0;

void func_80000D5C(u8 *arg0, s32 *arg1) {
    func_8012CA60(*arg1);
    func_80134760(arg1, M2C_FIELD(arg0, s32 *, 0x14C), M2C_FIELD(arg0, s32 *, 0x168), M2C_FIELD(arg0, u8 *, 0x14A), &D_80ACBA20, &D_80ACBA70, &D_80ACBAC0, arg0);
}
