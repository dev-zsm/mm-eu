// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0496.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6001360;
extern M2C_UNK D_80B46C34;
extern M2C_UNK D_80B491A0;

void func_800008BC(Actor *thisx) {
    func_801378E0((u8 *)thisx + 0x144, &D_6001360);
    M2C_FIELD(thisx, M2C_UNK **, 0x13C) = &D_80B491A0;
    func_800B6564(thisx, 0x3C656042);
    func_800B8C4C(thisx, 0x3873);
    M2C_FIELD(thisx, M2C_UNK **, 0x200) = &D_80B46C34;
}
