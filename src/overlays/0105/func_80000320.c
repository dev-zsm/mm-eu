// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B02EC(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E0FAC(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E1574(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E1C28(M2C_UNK, s32);                /* extern */
M2C_UNK func_800E1F64(M2C_UNK, s32);                /* extern */
M2C_UNK func_801A818C(s32);                         /* extern */

void func_80000320(u8 *arg0, M2C_UNK arg1) {
    func_800E1F64(arg1, arg0 + 0x808);
    func_800E0FAC(arg1, arg0 + 0x73C);
    func_800E1C28(arg1, arg0 + 0x788);
    func_800E1574(arg1, arg0 + 0x860);
    func_801A818C(arg0 + 0x338);
    func_800B02EC(arg1, M2C_FIELD(arg0, s32 *, 0x300));
}
