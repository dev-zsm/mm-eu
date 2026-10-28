// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012CA60(s32);                         /* extern */
M2C_UNK func_80134760(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80BA5F14;
extern M2C_UNK D_80BA5F54;
extern M2C_UNK D_80BA6018;

void func_800015C4(u8 *arg0, s32 *arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x1DC) != 0) {
        func_8012CA60(*arg1);
        func_80134760(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), M2C_FIELD(arg0, u8 *, 0x146), &D_80BA5F14, &D_80BA5F54, &D_80BA6018, arg0);
    }
}
