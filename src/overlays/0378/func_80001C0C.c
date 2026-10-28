// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(M2C_UNK);                     /* extern */
s32 func_800F1984(M2C_UNK);                         /* extern */
M2C_UNK func_800F1B24(M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_80A86690;

void func_80001C0C(u8 *arg0, M2C_UNK arg1) {
    if (func_800F1984(0xB) != 0) {
        func_800F1B24(0xB, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80A86690;
        return;
    }
    func_800F1944(0xB);
}
