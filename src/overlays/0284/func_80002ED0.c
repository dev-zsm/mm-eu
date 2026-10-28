// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, s32, u8 *); /* extern */
extern M2C_UNK D_601547C;
extern M2C_UNK D_809B818C;

void func_80002ED0(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f6;

    func_80137828(arg0 + 0x164, &D_601547C, M2C_FIELD(arg0, s32 *, 0x158), arg0);
    temp_f6 = (f32) func_80134AE8(&D_601547C);
    M2C_FIELD(arg0, M2C_UNK **, 0x464) = &D_809B818C;
    M2C_FIELD(arg0, f32 *, 0x1A8) = temp_f6;
}
