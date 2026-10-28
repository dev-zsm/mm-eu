// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_8096DE80(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
M2C_UNK func_8096E708(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_8096F1A8;
extern M2C_UNK D_8097109C;

void func_80001E58(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        func_8096DE80(arg0 + 0x14C, &D_8097109C, 2, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096F1A8;
    }
    func_800B680C(arg0);
    func_8096E708(arg0, 0x40400000);
}
