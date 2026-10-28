// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_80B901D4(u8 *);                      /* extern */
M2C_UNK func_80B90830(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern u8 D_801E7E1B;
extern M2C_UNK D_80B92BB4;

void func_800036E4(u8 *arg0, M2C_UNK arg1) {
    func_80B90830(arg0, 1, 1);
    func_80B901D4(arg0);
    if (D_801E7E1B & 0x10) {
        M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_80B92BB4;
    }
    func_800B680C(arg0);
}
