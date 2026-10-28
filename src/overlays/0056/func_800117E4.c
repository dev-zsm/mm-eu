// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D1C8(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_80830B44(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400DAC8;
extern M2C_UNK D_80849F78;

void func_800117E4(s32 arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_80849F78, 1);
    func_8082D1C8(arg1, arg0, &D_400DAC8);
}
