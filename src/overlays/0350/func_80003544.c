// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80A41A34(u8 *);                      /* extern */

void func_80003544(Actor *thisx) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(thisx, u8 **, 0x1C0);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x138) == 0)) {
        M2C_FIELD(thisx, u8 **, 0x1C0) = NULL;
    }
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x190)();
    func_80A41A34(thisx);
}
