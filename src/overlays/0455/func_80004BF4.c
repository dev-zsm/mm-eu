// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8, u8 *);                  /* extern */
extern M2C_UNK D_80AECE6C;
extern M2C_UNK D_80AEEC0C;

void func_80004BF4(u8 *arg0) {
    func_800F1944(M2C_FIELD(arg0, s8 *, 0x38), arg0);
    if (&D_80AECE6C == M2C_FIELD(arg0, M2C_UNK **, 0x188)) {
        M2C_FIELD(arg0, s16 *, 0x19C) = 1;
    } else {
        M2C_FIELD(arg0, s16 *, 0x19C) = 0;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AEEC0C;
}
