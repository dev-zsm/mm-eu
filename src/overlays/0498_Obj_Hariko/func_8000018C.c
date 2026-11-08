// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0498.h"

M2C_UNK func_80B4B8A8(u8 *);                      /* extern */

void ObjHariko_Update(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x144)();
    func_80B4B8A8(thisx);
}
