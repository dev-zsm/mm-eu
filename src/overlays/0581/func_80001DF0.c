// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_80BBE16C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80BBEE9C;
extern M2C_UNK D_80BBF258;

void func_80001DF0(u8 *arg0) {
    func_80BBE16C(arg0, 0, 1);
    func_800BD9E0(arg0 + 0x190, &D_80BBF258, 8);
    M2C_FIELD(arg0, s16 *, 0x31E) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D8) = &D_80BBEE9C;
}
