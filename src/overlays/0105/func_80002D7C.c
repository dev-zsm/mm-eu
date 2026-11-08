// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0105.h"

M2C_UNK func_800F1944(s8);                          /* extern */
extern M2C_UNK D_808C7404;

void func_80002D7C(Actor *thisx) {
    func_800F1944(M2C_FIELD(thisx, s8 *, 0x38));
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808C7404;
}
