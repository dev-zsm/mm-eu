// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B4B8A8(u8 *);                      /* extern */

void func_8000018C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x144)();
    func_80B4B8A8(arg0);
}
