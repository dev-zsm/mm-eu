// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808F985C(u8 *);                      /* extern */
M2C_UNK func_808F9F30(u8 *);                      /* extern */
M2C_UNK func_808F9FD0(u8 *);                      /* extern */
extern M2C_UNK D_808FA654;

void func_80001910(u8 *arg0) {
    s16 temp_v0;

    M2C_FIELD(arg0, s16 *, 0x1EE) = (s16) (M2C_FIELD(arg0, s16 *, 0x1EE) - 1);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1EE);
    if (temp_v0 == 0) {
        func_808F985C(arg0);
        func_808F9F30(arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808FA654;
        return;
    }
    if ((M2C_FIELD(arg0, u8 *, 0xB7) == 0) && (temp_v0 == 0x4D)) {
        func_808F985C(arg0);
        func_808F9FD0(arg0);
    }
}
