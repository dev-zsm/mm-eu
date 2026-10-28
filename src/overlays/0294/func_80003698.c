// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809F9054(u8 *);                      /* extern */
M2C_UNK func_809F90D8(u8 *);                      /* extern */
extern u8 D_801E7DFE;
extern M2C_UNK D_809F96E0;

void func_80003698(u8 *arg0) {
    if (!(D_801E7DFE & 4)) {
        func_809F9054(arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809F96E0;
        return;
    }
    func_809F90D8(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809F96E0;
}
