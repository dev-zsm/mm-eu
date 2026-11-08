// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0318.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80A1B104;
extern M2C_UNK D_80A1C0AC;
extern M2C_UNK D_80A1C2EC;

void func_80000370(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x13C) = &D_80A1C0AC;
    M2C_FIELD(thisx, s16 *, 0x2AA) = 0;
    func_800BD9E0((u8 *)thisx + 0x144, &D_80A1C2EC, 4, thisx);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80A1B104;
}
