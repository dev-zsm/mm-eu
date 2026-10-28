// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800897D0(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK D_80A82A40;

void func_80000020(void) {
    func_800897D0(&D_80A82A40, 0x264);
}
