// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80973CEC;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800B6564(thisx, 0x3F800000);
    M2C_FIELD(thisx, M2C_UNK **, 0x394) = &D_80973CEC;
}
