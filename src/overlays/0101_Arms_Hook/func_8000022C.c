// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0101.h"

M2C_UNK func_800FF3F4(u8 *, u8 *, u8 *, u8 *); /* extern */

void ArmsHook_AttachToActor(ArmsHook *this, Actor *actor) {
    M2C_FIELD(actor, s32 *, 4) = (s32) (M2C_FIELD(actor, s32 *, 4) | 0x2000);
    M2C_FIELD(this, u8 **, 0x1F8) = actor;
    func_800FF3F4((u8 *)actor + 0x24, (u8 *)this + 0x24, (u8 *)this + 0x1FC, actor);
}
