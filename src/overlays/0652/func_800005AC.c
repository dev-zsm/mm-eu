// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_80C0461C(u8 *);                      /* extern */

void func_800005AC(Actor *thisx) {
    s16 temp_v0;

    M2C_FIELD(thisx, M2C_UNK (**)(), 0x144)();
    func_80C0461C(thisx);
    temp_v0 = M2C_FIELD(thisx, s16 *, 0xD84);
    if (temp_v0 == 0) {
        func_800B6490(thisx);
        return;
    }
    M2C_FIELD(thisx, s16 *, 0xD84) = (s16) (temp_v0 - 1);
}
