// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808C9A1C();                            /* extern */
extern M2C_UNK D_808CAB24;

void func_80001368(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, s16 *, 0x14A) = 0xA;
    func_808C9A1C();
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808CAB24;
}
