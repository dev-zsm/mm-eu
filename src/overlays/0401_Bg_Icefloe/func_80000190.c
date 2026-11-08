// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0401.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80138F50(s32, u8 *, u8 *, u8 *); /* extern */
extern M2C_UNK D_80AA9818;

void func_80000190(BgIcefloe *this, PlayState *play) {
    M2C_FIELD(this, s32 *, 0x160) = 0x14;
    func_80138F50((u8 *)play + 0x187B0, (u8 *)this + 0x24, (u8 *)this + 0xEC, (u8 *)this + 0xF8);
    func_800B8C4C(this, 0x2862);
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80AA9818;
}
