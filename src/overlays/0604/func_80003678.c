// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80134760(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80BD4D54;
extern M2C_UNK D_80BD4F18;
extern M2C_UNK D_80BD4F30;

void func_80003678(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_80134760(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), M2C_FIELD(arg0, u8 *, 0x146), &D_80BD4D54, &D_80BD4F18, &D_80BD4F30, arg0);
}
