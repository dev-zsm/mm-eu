// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80A54028;
extern M2C_UNK D_80A55138;

void func_800001D0(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x1DC) = 1;
    M2C_FIELD(arg0, u16 *, 0x2B0) = (u16) (M2C_FIELD(arg0, u16 *, 0x2B0) & 0xFFFE);
    func_800BD9E0(arg0 + 0x144, &D_80A55138, 5, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80A54028;
}
