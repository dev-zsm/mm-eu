// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0506.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_80B56788;
extern M2C_UNK D_80B58000;

void func_80001148(Actor *thisx) {
    func_800B8C4C(thisx, 0x3831);
    func_800BD9E0((u8 *)thisx + 0x1E4, &D_80B58000, 2);
    M2C_FIELD(thisx, M2C_UNK **, 0x228) = &D_80B56788;
}
