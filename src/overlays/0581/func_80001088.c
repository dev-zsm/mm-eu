// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BBD290(u8 *);                      /* extern */

void func_80001088(u8 *arg0) {
    u8 *temp_v0;

    func_80BBD290(arg0);
    temp_v0 = M2C_FIELD(arg0, u8 **, 0x124);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s16 *, 0) == 5)) {
        M2C_FIELD(temp_v0, s8 *, 0x1A7) = -0x32;
    }
}
