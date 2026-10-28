// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6009808;
extern M2C_UNK D_809764BC;

void func_80001428(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6009808, 0xC0800000);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_809764BC;
}
