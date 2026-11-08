// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0260.h"

M2C_UNK func_800B6730(s32);                         /* extern */
M2C_UNK func_8098FBA0(s32);                         /* extern */
M2C_UNK func_8098FBD4(s32, M2C_UNK);                /* extern */

void ObjGrassCarry_UpdatePos(ObjGrassCarry *this) {
    func_8098FBA0(this);
    func_8098FBD4((u8 *)this + 0x64, 0x3D4CCCCD);
    func_800B6730(this);
}
