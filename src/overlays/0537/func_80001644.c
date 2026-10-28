// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B84584(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B8460C(u8 *);                      /* extern */
extern u8 D_801E7E37;
extern M2C_UNK D_80B85780;

void func_80001644(u8 *arg0, M2C_UNK arg1) {
    func_80B8460C(arg0);
    if (D_801E7E37 & 1) {
        M2C_FIELD(arg0, M2C_UNK **, 0x314) = &D_80B85780;
        func_80B84584(arg0, 0, 2);
        M2C_FIELD(arg0, s16 *, 0x304) = 5;
    }
}
