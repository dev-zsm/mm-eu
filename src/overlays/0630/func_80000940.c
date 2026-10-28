// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80131AF8(s32, s32, u8 *);            /* extern */
extern M2C_UNK D_600C308;

void func_80000940(u8 *arg0, s32 arg1) {
    func_80131AF8(arg1, M2C_FIELD(arg0, s32 *, 0x15C), arg0);
    func_800BDD44(arg1, &D_600C308);
}
