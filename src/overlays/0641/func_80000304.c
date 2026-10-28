// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BFD978(u8 *);                      /* extern */

void func_80000304(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x188)();
    func_80137070(arg0 + 0x144);
    func_80BFD978(arg0);
}
