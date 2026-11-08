// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0368.h"

M2C_UNK func_800E7D4C(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_8018132C(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK func_8018142C(f32, f32, s32, M2C_UNK);      /* extern */

void ObjMine_Air_InitCollider(ObjMine *this, s32 linkCount) {
    func_8018132C(M2C_FIELD(this, f32 *, 0x24), M2C_FIELD(this, f32 *, 0x28), M2C_FIELD(this, s32 *, 0x2C), 0);
    func_8018142C(M2C_FIELD(this, f32 *, 0x58), M2C_FIELD(this, f32 *, 0x5C), M2C_FIELD(this, s32 *, 0x60), 1);
    func_800E7D4C(0, (u8 *)this + 0x144);
}
