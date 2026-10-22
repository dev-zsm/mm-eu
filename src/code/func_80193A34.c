// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8008F3E0(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_801F4980;
extern M2C_UNK D_801F4998;

void func_80193A34(void) {
    func_8008F3E0(&D_801F4980, &D_801F4998, 0x10);
}
