// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_8012C78C(s32);                         /* extern */
M2C_UNK func_80133EDC(u8 *, s32, s32, M2C_UNK *, s32, u8 *); /* extern */
extern M2C_UNK D_80A97308;

void func_8000080C(u8 *arg0, u8 *arg1) {
    if ((M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) && (M2C_FIELD(arg0, u8 *, 0x22E) != 0)) {
        func_8012C73C(M2C_FIELD(arg1, s32 *, 0));
        func_8012C78C(M2C_FIELD(arg1, s32 *, 0));
        func_80133EDC(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), &D_80A97308, 0, arg0);
    }
}
