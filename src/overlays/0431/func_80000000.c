// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80AC63D0;
extern M2C_UNK D_80AC6800;

void func_80000000(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x232) = 0x14;
    M2C_FIELD(arg0, s16 *, 0x230) = 0;
    func_800BD9E0(arg0 + 0x190, &D_80AC6800, 0, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AC63D0;
}
