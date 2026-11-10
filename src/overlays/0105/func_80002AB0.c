#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5CA0(u8 *, s8);                  /* extern */
M2C_UNK func_800B6FD0(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_800F1D6C(s8);                          /* extern */
extern M2C_UNK D_808C717C;

void func_80002AB0(u8 *arg0, u8 *arg1) {
    func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
    func_800B6FD0(arg1, arg0, 6);
    func_800B5CA0(arg1, M2C_FIELD(arg1, s8 *, 0x186E0));
    M2C_FIELD(arg0, s16 *, 0x2EE) = 0xFF;
    M2C_FIELD(arg1, u8 *, 0x170C7) = 0xFF;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808C717C;
}
