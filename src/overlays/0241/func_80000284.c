// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8097CA78;

void func_80000284(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x19A) = (s16) (M2C_FIELD(arg0, s16 *, 0x19A) & 0xFDFF);
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_8097CA78;
}
