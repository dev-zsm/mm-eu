// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0572.h"

M2C_UNK func_80BB92A0(u8 *);                      /* extern */

void ObjHgdoor_Update(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x15C)();
    func_80BB92A0(thisx);
}
