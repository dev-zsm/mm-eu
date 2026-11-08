// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0559.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_80BAA410;
extern M2C_UNK D_80BAB5A8;

void func_800006FC(Actor *thisx) {
    func_800BD9E0((u8 *)thisx + 0x1F0, &D_80BAB5A8, 2);
    M2C_FIELD(thisx, M2C_UNK **, 0x234) = &D_80BAA410;
}
