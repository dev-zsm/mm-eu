// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013E578(s32, M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK D_809B243C;
extern M2C_UNK D_809B29AC;

void func_800008E0(u8 *arg0, M2C_UNK arg1) {
    func_8013E578(arg0 + 0x148, &D_809B29AC, 2, arg0 + 0x298);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809B243C;
}
