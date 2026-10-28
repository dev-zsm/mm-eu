// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80133EDC(s32 *, s32, s32, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80A36AD8;
extern M2C_UNK D_80A36B04;

void func_80000AD0(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_80133EDC(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), &D_80A36AD8, &D_80A36B04, arg0);
}
