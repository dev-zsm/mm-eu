// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600A954;
extern M2C_UNK D_809CB8F0;

void func_80004410(u8 *arg0, M2C_UNK arg1) {
    func_80137934(arg0 + 0x148, &D_600A954, 0xC1200000, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_809CB8F0;
    M2C_FIELD(arg0, s16 *, 0x24C) = 0x1E;
}
